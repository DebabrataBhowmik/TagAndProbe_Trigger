### The recipe described here produces the trigger efficiency of electron triggers using Tag and Probe method.
#### The steps are described below.
##### The input to this code is a flat root tree containing the branches needed for calculation.
##### The tree is produced using the following code : https://github.com/arunhep/TagAndProbe_Trigger/blob/LPC_HATs2021/NtupleProducer

### Description of Files
   * *test.txt* : it contains the path of input root file
   * *TagAndProbe_Ele.C* : main macro to apply tag and probe procedure and producing the histograms of passing and failing probes
   * *TagAndProbe_Ele.h* : header file
   * *compileNrun_tnp.sh* : script to compile and run the macros : follow the interactive steps
   * *histNames_Ele.txt* : list the histograms you want to plot
   * *AllRootFiles.txt* : input file for plotting (output of *compileNrun_tnp.sh*)
   * *runPlotting.sh* : script to make the plots. It runs *plotEfficiency.C* taking *histNames_Ele.txt* and *AllRootFiles.txt* as input

### Steps

<br>  
sh compileNrun_tnp.sh TagAndProbe_Ele.C

./runPlotting.sh histNames_Ele.txt
<br>  

#### This produces the *png*, *txt* and *root* files for every trigger (trigger leg in case of double electron trigger).
