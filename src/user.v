module user(
    input wire clk100m,
    input wire rstn,

    input wire en
);

    // Gate the clock using based on clken
    wire clk;
    BUFGCE clk_bufg (
        .I(clk100m),
        .CE(en),
        .O(clk)
    );

    // Instatiate NUM_MODS user modules
    localparam NUM_MODS = 100;
    genvar i;
    generate for (i = 0; i < NUM_MODS; i = i + 1) begin: gen_duts
        // instantiate a single block ram
    endgenerate
endmodule