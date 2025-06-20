module user(
    input wire clk100m,
    input wire rstn,

    input wire [31:0] pwr_en_in,
    output reg [31:0] dummy_out,

    output reg [15:0] leds
);
    // Instatiate NUM_MODULES user modules
    localparam NUM_MODULES = 32;
    genvar i;
    generate for (i = 0; i < NUM_MODULES; i = i + 1) begin: gen_duts
        // Sandwich user module in registers
        reg pwr_en;
        wire dummy;

        always @(posedge clk100m) begin
            if (!rstn) begin
                pwr_en <= 1'b0;
                dummy_out[i] <= 1'b0;
            end else begin
                pwr_en <= pwr_en_in[i];
                dummy_out[i] <= dummy;
            end
        end

        // Generate random values with an LFSR (65534 cycles period)
        reg [15:0] lfsr;
        reg [31:0] counter;

        wire bit;
        assign bit = ((lfsr[0]) ^ (lfsr[2]) ^ (lfsr[3]) ^ (lfsr[5]));

        always @(posedge clk100m) begin
            if (!rstn) begin
                lfsr <= (i + 1); // Initialize LFSR with module index (non-zero)
                counter <= 0;
            end else if (counter == 0) begin
                lfsr <= {bit, lfsr[15:1]};
            end else if (counter < 50000000) begin
                counter <= counter + 1;
            end else begin
                counter <= 0;
            end
        end

        if (i == 0) begin
            always @(posedge clk100m) begin
                leds <= lfsr; // Assign LFSR value to LEDs for module 0
            end
        end

        // Generate user module instances to be enabled if pwr_en is high
        //   and to generate dummy output in order to not get optimized out.
    end endgenerate
endmodule