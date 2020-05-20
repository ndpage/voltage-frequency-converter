# voltage-frequency-converter

Short sketch to convert a voltage input to a frequency output on Arduino UNO
The analog input pin A0 is used to read the voltage provided by an external voltage source. The UNO takes this voltage and scales it to a predetermined value based on the maximum frequency specified in the code. The scaled frequency is then used to set the switching frequency of digital output pin 2.
