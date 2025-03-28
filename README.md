# Test Git Actions for MPLAB Projects
![Build Status](https://github.com/Lucho-rar/test-mplab/actions/workflows/build.yml/badge.svg)

## Objetive
Integration for sensor development.

# Function
Generates a environment for compile MPLABs code, especially for PIC16F1XXXX, and uploads `.hex` in the artifacts from GitActions pipeline.

## Task for made in the Main Project
- [x] Integration with MPLAB and XC8 for PIC16F18425.
- [ ] Integration for all sensors v2.
- [x] Integration for all sensors v3.
- [ ] Dockerization.
- [ ] DualOS runner for win and linux (at the moment only linux).


## Need
So that the runner on GActions does not have compile errors, use this versions:

<span style="color:red">High</span>
- XC8: V2.36 (This follows creation code's. Too you can try with V2.45 but take into account that the runner execute in the v2.36 )

<span style="color:red">High</span>
- PIC16F1xxxx atpack: V1.15.191 (This follows creation and environment code's. With other version its very probability that you have compiler errors)

<span style="color:yellow">Medium</span>
- MPLAB: v6.00. This have minor priority because with other versions at local (how v6.25) not have a problems. But this is the version that use the runner.

## How execute?
Add the .X project in the `firmware/` folder and integrate in de `build.yml` the job and PATH. 

## Note
At the moment only run with Linux systems so that you probability made run the code in the Linux machine locally, above all for paths genereation. Otherwise you have errors with system paths.






Inspirated in: https://github.com/jeandeaual/mplabx-xc8-build-action