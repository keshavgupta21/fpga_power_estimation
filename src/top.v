module top(
    input wire clk100m,
    input wire rstn,
    output reg [15:0] leds
);

    // blink the led at 1 hz
    reg [31:0] counter = 0;
    always @(posedge clk100m) begin
        if (!rstn) begin
            leds <= 16'h0001;
        end else begin
            if (counter >= 50000000) begin
                counter <= 0;
                leds <= {leds[14:0], leds[15]};
            end else begin
                counter <= counter + 1;
            end
        end
    end

    

endmodule