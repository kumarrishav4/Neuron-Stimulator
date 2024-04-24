1. This model creates a myelinated nerve fiber of 55 nodes, 16 um outer diameter and 10 um inner diameter. The separation between consecutive nodes is 1.6 mm.
2. Before running the simulation, you must compile the provided mechanisms (fh.mod and xtra.mod). Compilation can be done by double-clicking mknrndll in the Neuron folder.
3. To run the simulation, double-click init.hoc.
4. Once you run the simulation, you should get two plots: (1) a time plot of Vm and (2) a space plot of Vm.
5. To find the stimulation threshold (minimum DC source voltage that leads to a spike), use "ScalingFactor" in the "Settings" panel.
6. This folder also contains two sample input files: (1) dIdt_norm.txt and (2) dEdX.txt. These sample files are given so that you can test the Neuron simulation. These are not the correct input files for the test case. The correct input files are to be computed by performing part A and part B of the project.