# Production & Manufacturing

This folder contains the production assets, slicing profiles, print-ready files, and fabrication guides for producing the physical parts of the syringe pump.

## Planned Folder Contents

- **Print-Ready G-codes**: Pre-sliced G-code files tuned for reliable printing of custom brackets and mounts.
- **Slicer Profiles / Project Files**: `.3mf` files containing recommended print orientations, support structures, infill density, and wall line counts.
- **Fabrication Notes / Checklists**: Instructions for any post-processing, tapping threads, heat-set insert installation, or frame modification.

## 3D Printing Guidelines

Because syringe pumps exert steady axial mechanical force during operation, printed components must be rigid and resistant to layer delamination:

| Parameter | Recommended Setting | Build Value |
| :--- | :--- | :--- |
| **Material** | PETG, ABS, ASA, or high-toughness PLA+ | `[SPECIFY: Chosen filament]` |
| **Layer Height** | 0.20 mm | `[SPECIFY: Layer height]` |
| **Perimeters / Walls** | Minimum 4 to 5 walls | `[SPECIFY: Wall count]` |
| **Top & Bottom Layers**| 4 to 5 layers | `[SPECIFY: Top/Bottom count]` |
| **Infill** | 35% - 50% (Gyroid or Grid) | `[SPECIFY: Infill % and pattern]` |
| **Heat-Set Inserts** | Brass M3/M4 threaded inserts (if used) | `[SPECIFY: Insert sizes]` |

## Production Files to Add

- [ ] `[INSERT FILE: Syringe clamp 3MF / print file]`
- [ ] `[INSERT FILE: Plunger pusher 3MF / print file]`
- [ ] `[INSERT FILE: Limit switch mount 3MF / print file]`
- [ ] `[INSERT FILE: Any additional bracket or cable guide files]`

## Fabrication Visuals

`[INSERT PHOTO: 3D printed parts fresh off the print bed]`

`[INSERT PHOTO: Heat-set inserts or hardware installation]`

