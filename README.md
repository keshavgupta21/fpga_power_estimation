# Steps to replicate project

1. Make a vivado project with appropriate board.
2. Add appropriate constraints from xdc
3. Add files from src, ip.
4. Generate block design from bd (run tcl script)
5. Create HDL wrapper for the block design, set it as top
6. Generate bitstream and export hardware to get the .xsa file (hw platform description)
7. Make a new vitis project (platform component) with the given xsa file, standalone os into controller_platform folder
8. Make a new vitis example from template (empty application) with the given platform
9. Include fw/main.c into sources and build.
10. Associate the resulting ELF file with the microblaze.
11. Generate bitstream and run.

# Notes
- platform_lib in fw is olny used for reference, not actually built with.

# TODOs
- Script to generate vivado (and vitis?) project for a board all at once

