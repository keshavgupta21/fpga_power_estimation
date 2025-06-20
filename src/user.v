module user(
    input wire clk100m,
    input wire rstn,

    input wire pwr_en
);
    // Instatiate NUM_MODS user modules
    localparam NUM_MODS = 100;
    genvar i;
    generate for (i = 0; i < NUM_MODS; i = i + 1) begin: gen_duts
        // instantiate a single block ram
    endgenerate
endmodule