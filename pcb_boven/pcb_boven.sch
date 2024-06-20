EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "Upper_pcb"
Date ""
Rev ""
Comp "Mendelcollege"
Comment1 "For more info email 10810@mendelcollege.nl"
Comment2 "https://github.com/ableTI/robotica/"
Comment3 "https://mendelcollege.nl/ontdek-je-talenten/robotica-en-beta/"
Comment4 ""
$EndDescr
$Comp
L openmv_m7_r2:openMV_M7_R2 U2
U 1 1 66360711
P 9350 5325
F 0 "U2" H 9350 6490 50  0000 C CNN
F 1 "openMV_M7_R2" H 9350 6399 50  0000 C CNN
F 2 "custom:openmv_m7_r2" H 9350 6675 50  0001 C CNN
F 3 "" H 9350 6675 50  0001 C CNN
	1    9350 5325
	1    0    0    -1  
$EndComp
$Comp
L Interface_Expansion:MCP23017_SP Portmultiplexer1
U 1 1 663613E1
P 11025 7900
F 0 "Portmultiplexer1" H 11025 9181 50  0000 C CNN
F 1 "MCP23017_SP" H 11025 9090 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 11225 6900 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001952C.pdf" H 11225 6800 50  0001 L CNN
	1    11025 7900
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_1
U 1 1 663625BE
P 825 325
F 0 "ir_sensor_1" H 1153 -136 50  0000 L CNN
F 1 "tssp4038" H 1153 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 825 425 50  0001 C CNN
F 3 "" H 825 425 50  0001 C CNN
	1    825  325 
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 goal_kleur1
U 1 1 66365885
P 10775 5125
F 0 "goal_kleur1" H 10775 4858 50  0000 C CNN
F 1 "SW_DIP_x01" H 10775 4949 50  0000 C CNN
F 2 "custom:dipswitch1" H 10775 5125 50  0001 C CNN
F 3 "~" H 10775 5125 50  0001 C CNN
	1    10775 5125
	-1   0    0    1   
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_2
U 1 1 6638ABBB
P 1900 325
F 0 "ir_sensor_2" H 2228 -136 50  0000 L CNN
F 1 "tssp4038" H 2228 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 1900 425 50  0001 C CNN
F 3 "" H 1900 425 50  0001 C CNN
	1    1900 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_3
U 1 1 6638EAFC
P 2975 325
F 0 "ir_sensor_3" H 3303 -136 50  0000 L CNN
F 1 "tssp4038" H 3303 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 2975 425 50  0001 C CNN
F 3 "" H 2975 425 50  0001 C CNN
	1    2975 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_4
U 1 1 6638EB02
P 4050 325
F 0 "ir_sensor_4" H 4378 -136 50  0000 L CNN
F 1 "tssp4038" H 4378 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 4050 425 50  0001 C CNN
F 3 "" H 4050 425 50  0001 C CNN
	1    4050 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_5
U 1 1 66396AFC
P 5125 325
F 0 "ir_sensor_5" H 5453 -136 50  0000 L CNN
F 1 "tssp4038" H 5453 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 5125 425 50  0001 C CNN
F 3 "" H 5125 425 50  0001 C CNN
	1    5125 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_6
U 1 1 66396B02
P 6200 325
F 0 "ir_sensor_6" H 6528 -136 50  0000 L CNN
F 1 "tssp4038" H 6528 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 6200 425 50  0001 C CNN
F 3 "" H 6200 425 50  0001 C CNN
	1    6200 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_7
U 1 1 66396B08
P 7275 325
F 0 "ir_sensor_7" H 7603 -136 50  0000 L CNN
F 1 "tssp4038" H 7603 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 7275 425 50  0001 C CNN
F 3 "" H 7275 425 50  0001 C CNN
	1    7275 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_8
U 1 1 66396B0E
P 8350 325
F 0 "ir_sensor_8" H 8678 -136 50  0000 L CNN
F 1 "tssp4038" H 8678 -227 50  0000 L CNN
F 2 "custom:tssp4038" H 8350 425 50  0001 C CNN
F 3 "" H 8350 425 50  0001 C CNN
	1    8350 325 
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_9
U 1 1 663A4C26
P 825 1475
F 0 "ir_sensor_9" H 1153 1014 50  0000 L CNN
F 1 "tssp4038" H 1153 923 50  0000 L CNN
F 2 "custom:tssp4038" H 825 1575 50  0001 C CNN
F 3 "" H 825 1575 50  0001 C CNN
	1    825  1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_10
U 1 1 663A4C2C
P 1900 1475
F 0 "ir_sensor_10" H 2228 1014 50  0000 L CNN
F 1 "tssp4038" H 2228 923 50  0000 L CNN
F 2 "custom:tssp4038" H 1900 1575 50  0001 C CNN
F 3 "" H 1900 1575 50  0001 C CNN
	1    1900 1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_11
U 1 1 663A4C32
P 2975 1475
F 0 "ir_sensor_11" H 3303 1014 50  0000 L CNN
F 1 "tssp4038" H 3303 923 50  0000 L CNN
F 2 "custom:tssp4038" H 2975 1575 50  0001 C CNN
F 3 "" H 2975 1575 50  0001 C CNN
	1    2975 1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_12
U 1 1 663A4C38
P 4050 1475
F 0 "ir_sensor_12" H 4378 1014 50  0000 L CNN
F 1 "tssp4038" H 4378 923 50  0000 L CNN
F 2 "custom:tssp4038" H 4050 1575 50  0001 C CNN
F 3 "" H 4050 1575 50  0001 C CNN
	1    4050 1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_13
U 1 1 663A4C3E
P 5125 1475
F 0 "ir_sensor_13" H 5453 1014 50  0000 L CNN
F 1 "tssp4038" H 5453 923 50  0000 L CNN
F 2 "custom:tssp4038" H 5125 1575 50  0001 C CNN
F 3 "" H 5125 1575 50  0001 C CNN
	1    5125 1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_14
U 1 1 663A4C44
P 6200 1475
F 0 "ir_sensor_14" H 6528 1014 50  0000 L CNN
F 1 "tssp4038" H 6528 923 50  0000 L CNN
F 2 "custom:tssp4038" H 6200 1575 50  0001 C CNN
F 3 "" H 6200 1575 50  0001 C CNN
	1    6200 1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_15
U 1 1 663A4C4A
P 7275 1475
F 0 "ir_sensor_15" H 7603 1014 50  0000 L CNN
F 1 "tssp4038" H 7603 923 50  0000 L CNN
F 2 "custom:tssp4038" H 7275 1575 50  0001 C CNN
F 3 "" H 7275 1575 50  0001 C CNN
	1    7275 1475
	1    0    0    -1  
$EndComp
$Comp
L tssp4038:tssp4038 ir_sensor_16
U 1 1 663A4C50
P 8350 1475
F 0 "ir_sensor_16" H 8678 1014 50  0000 L CNN
F 1 "tssp4038" H 8678 923 50  0000 L CNN
F 2 "custom:tssp4038" H 8350 1575 50  0001 C CNN
F 3 "" H 8350 1575 50  0001 C CNN
	1    8350 1475
	1    0    0    -1  
$EndComp
Wire Wire Line
	7225 7300 7350 7300
Wire Wire Line
	8100 7300 8100 10775
Wire Wire Line
	8100 10775 3450 10775
Text GLabel 1300 10775 0    50   Input ~ 0
scl
Wire Wire Line
	7225 7400 7425 7400
Wire Wire Line
	8075 7400 8075 10675
Wire Wire Line
	8075 10675 3400 10675
Text GLabel 1300 10675 0    50   Input ~ 0
sda
Wire Wire Line
	7225 6700 7550 6700
Wire Wire Line
	8125 6700 8125 10875
Text GLabel 1300 10875 0    50   Input ~ 0
gnd
Wire Wire Line
	7225 6600 7675 6600
Wire Wire Line
	8150 6600 8150 10975
Wire Wire Line
	8150 10975 2600 10975
Text GLabel 1300 10975 0    50   Input ~ 0
5v
Text Notes 975  11100 0    50   ~ 0
naar pcb onder
Text GLabel 1300 10475 0    50   Input ~ 0
sd6
Text GLabel 1300 10575 0    50   Input ~ 0
sc6
Wire Wire Line
	9950 5825 10025 5825
Wire Wire Line
	9075 10275 9075 6800
Wire Wire Line
	8700 5825 8750 5825
Wire Wire Line
	950  10275 2775 10275
Text GLabel 1300 10275 0    50   Input ~ 0
3.3v
Wire Wire Line
	11025 6800 9075 6800
Connection ~ 9075 6800
Wire Wire Line
	9075 6800 8700 6800
Wire Wire Line
	8700 5825 8700 6800
Wire Wire Line
	825  2275 825  2350
Wire Wire Line
	825  2350 1175 2350
Wire Wire Line
	1900 2350 1900 2275
Wire Wire Line
	1900 2350 2975 2350
Wire Wire Line
	2975 2350 2975 2275
Connection ~ 1900 2350
Wire Wire Line
	2975 2350 4050 2350
Wire Wire Line
	4050 2350 4050 2275
Connection ~ 2975 2350
Wire Wire Line
	4050 2350 5125 2350
Wire Wire Line
	5125 2350 5125 2275
Connection ~ 4050 2350
Wire Wire Line
	5125 2350 6200 2350
Wire Wire Line
	6200 2350 6200 2275
Connection ~ 5125 2350
Wire Wire Line
	6200 2350 7275 2350
Wire Wire Line
	7275 2350 7275 2275
Connection ~ 6200 2350
Wire Wire Line
	7275 2350 8350 2350
Wire Wire Line
	8350 2350 8350 2275
Connection ~ 7275 2350
Wire Wire Line
	8350 1125 8350 1200
Wire Wire Line
	8350 1200 7275 1200
Wire Wire Line
	7275 1200 7275 1125
Wire Wire Line
	7275 1200 6200 1200
Wire Wire Line
	6200 1200 6200 1125
Connection ~ 7275 1200
Wire Wire Line
	6200 1200 5125 1200
Wire Wire Line
	5125 1200 5125 1125
Connection ~ 6200 1200
Wire Wire Line
	5125 1200 4050 1200
Wire Wire Line
	4050 1200 4050 1125
Connection ~ 5125 1200
Wire Wire Line
	4050 1200 2975 1200
Wire Wire Line
	2975 1200 2975 1125
Connection ~ 4050 1200
Wire Wire Line
	2975 1200 1900 1200
Wire Wire Line
	1900 1200 1900 1125
Connection ~ 2975 1200
Wire Wire Line
	825  1200 825  1125
Connection ~ 1900 1200
Wire Wire Line
	675  1125 675  1225
Wire Wire Line
	675  1225 1150 1225
Wire Wire Line
	1750 1225 1750 1125
Wire Wire Line
	1750 1225 2825 1225
Wire Wire Line
	2825 1225 2825 1125
Connection ~ 1750 1225
Wire Wire Line
	2825 1225 3900 1225
Wire Wire Line
	3900 1225 3900 1125
Connection ~ 2825 1225
Wire Wire Line
	3900 1225 4975 1225
Wire Wire Line
	4975 1225 4975 1125
Connection ~ 3900 1225
Wire Wire Line
	4975 1225 6050 1225
Wire Wire Line
	6050 1225 6050 1125
Connection ~ 4975 1225
Wire Wire Line
	6050 1225 7125 1225
Wire Wire Line
	7125 1225 7125 1125
Connection ~ 6050 1225
Wire Wire Line
	7125 1225 8200 1225
Wire Wire Line
	8200 1225 8200 1125
Connection ~ 7125 1225
Wire Wire Line
	8200 2275 8200 2375
Wire Wire Line
	8200 2375 7125 2375
Wire Wire Line
	7125 2375 7125 2275
Wire Wire Line
	7125 2375 6050 2375
Wire Wire Line
	6050 2375 6050 2275
Connection ~ 7125 2375
Wire Wire Line
	6050 2375 4975 2375
Wire Wire Line
	4975 2375 4975 2275
Connection ~ 6050 2375
Wire Wire Line
	4975 2375 3900 2375
Wire Wire Line
	3900 2375 3900 2275
Connection ~ 4975 2375
Wire Wire Line
	3900 2375 2825 2375
Wire Wire Line
	2825 2375 2825 2275
Connection ~ 3900 2375
Wire Wire Line
	2825 2375 1750 2375
Wire Wire Line
	1750 2375 1750 2275
Connection ~ 2825 2375
Wire Wire Line
	1750 2375 1150 2375
Wire Wire Line
	675  2375 675  2275
Connection ~ 1750 2375
Wire Wire Line
	1150 2375 1150 1225
Connection ~ 1150 2375
Wire Wire Line
	1150 2375 675  2375
Connection ~ 1150 1225
Wire Wire Line
	1150 1225 1750 1225
Wire Wire Line
	1175 2350 1175 1200
Wire Wire Line
	825  1200 1175 1200
Connection ~ 1175 2350
Wire Wire Line
	1175 2350 1900 2350
Connection ~ 1175 1200
Wire Wire Line
	1175 1200 1900 1200
Wire Wire Line
	975  1125 975  1625
Wire Wire Line
	2050 1125 2050 1600
Wire Wire Line
	3125 1125 3125 1575
Wire Wire Line
	4200 1125 4200 1550
Wire Wire Line
	5275 1125 5275 1525
Wire Wire Line
	6350 1125 6350 1500
Wire Wire Line
	7425 1125 7425 1475
Wire Wire Line
	8500 1125 8500 1450
Wire Wire Line
	3125 2725 3125 2275
Wire Wire Line
	2050 2275 2050 2750
Wire Wire Line
	975  2275 975  2775
Wire Wire Line
	11875 2775 11875 7100
Wire Wire Line
	11875 7100 11725 7100
Wire Wire Line
	975  2775 11875 2775
Wire Wire Line
	11725 7200 11900 7200
Wire Wire Line
	11900 7200 11900 2750
Wire Wire Line
	2050 2750 11900 2750
Wire Wire Line
	11925 2725 11925 7300
Wire Wire Line
	11925 7300 11725 7300
Wire Wire Line
	3125 2725 11925 2725
Wire Wire Line
	11725 7400 11950 7400
Wire Wire Line
	11950 7400 11950 2700
Wire Wire Line
	11975 2675 11975 7500
Wire Wire Line
	11975 7500 11725 7500
Wire Wire Line
	11725 7600 12000 7600
Wire Wire Line
	12000 7600 12000 2650
Wire Wire Line
	12025 2625 12025 7700
Wire Wire Line
	12025 7700 11725 7700
Wire Wire Line
	4200 2275 4200 2700
Wire Wire Line
	4200 2700 11950 2700
Wire Wire Line
	5275 2275 5275 2675
Wire Wire Line
	5275 2675 11975 2675
Wire Wire Line
	6350 2275 6350 2650
Wire Wire Line
	6350 2650 12000 2650
Wire Wire Line
	7425 2275 7425 2625
Wire Wire Line
	7425 2625 12025 2625
Wire Wire Line
	8500 2275 8500 2600
Wire Wire Line
	8500 2600 12050 2600
Wire Wire Line
	12050 2600 12050 7800
Wire Wire Line
	12050 7800 11725 7800
Wire Wire Line
	12075 1625 12075 8000
Wire Wire Line
	12075 8000 11725 8000
Wire Wire Line
	975  1625 12075 1625
Wire Wire Line
	11725 8100 12100 8100
Wire Wire Line
	12100 8100 12100 1600
Wire Wire Line
	2050 1600 12100 1600
Wire Wire Line
	12125 1575 12125 8200
Wire Wire Line
	12125 8200 11725 8200
Wire Wire Line
	3125 1575 12125 1575
Wire Wire Line
	11725 8300 12150 8300
Wire Wire Line
	12150 8300 12150 1550
Wire Wire Line
	4200 1550 12150 1550
Wire Wire Line
	12175 1525 12175 8400
Wire Wire Line
	12175 8400 11725 8400
Wire Wire Line
	5275 1525 12175 1525
Wire Wire Line
	11725 8500 12200 8500
Wire Wire Line
	12200 8500 12200 1500
Wire Wire Line
	6350 1500 12200 1500
Wire Wire Line
	12225 1475 12225 8600
Wire Wire Line
	12225 8600 11725 8600
Wire Wire Line
	7425 1475 12225 1475
Wire Wire Line
	11725 8700 12250 8700
Wire Wire Line
	12250 8700 12250 1450
Wire Wire Line
	8500 1450 12250 1450
$Comp
L Device:R R2
U 1 1 6652784E
P 4050 6175
F 0 "R2" V 3843 6175 50  0000 C CNN
F 1 "R" V 3934 6175 50  0000 C CNN
F 2 "custom:resistor" V 3980 6175 50  0001 C CNN
F 3 "~" H 4050 6175 50  0001 C CNN
	1    4050 6175
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 66537A44
P 4200 6175
F 0 "R3" V 3993 6175 50  0000 C CNN
F 1 "R" V 4084 6175 50  0000 C CNN
F 2 "custom:resistor" V 4130 6175 50  0001 C CNN
F 3 "~" H 4200 6175 50  0001 C CNN
	1    4200 6175
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 66545F04
P 4350 6175
F 0 "R4" V 4143 6175 50  0000 C CNN
F 1 "R" V 4234 6175 50  0000 C CNN
F 2 "custom:resistor" V 4280 6175 50  0001 C CNN
F 3 "~" H 4350 6175 50  0001 C CNN
	1    4350 6175
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 6654CD89
P 4500 6175
F 0 "R5" V 4293 6175 50  0000 C CNN
F 1 "R" V 4384 6175 50  0000 C CNN
F 2 "custom:resistor" V 4430 6175 50  0001 C CNN
F 3 "~" H 4500 6175 50  0001 C CNN
	1    4500 6175
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 665A1C89
P 10225 4600
F 0 "R1" V 10018 4600 50  0000 C CNN
F 1 "R" V 10109 4600 50  0000 C CNN
F 2 "custom:resistor" V 10155 4600 50  0001 C CNN
F 3 "~" H 10225 4600 50  0001 C CNN
	1    10225 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5025 6900 4050 6900
Wire Wire Line
	5025 7000 4200 7000
Wire Wire Line
	3875 7100 4350 7100
Wire Wire Line
	5025 7200 4500 7200
Wire Wire Line
	4050 6325 4050 6900
Connection ~ 4050 6900
Wire Wire Line
	4050 6900 3875 6900
Wire Wire Line
	4200 6325 4200 7000
Connection ~ 4200 7000
Wire Wire Line
	4200 7000 3875 7000
Wire Wire Line
	4350 6325 4350 7100
Connection ~ 4350 7100
Wire Wire Line
	4350 7100 5025 7100
Wire Wire Line
	4500 6325 4500 7200
Connection ~ 4500 7200
Wire Wire Line
	4500 7200 3875 7200
Wire Wire Line
	3275 7200 3275 7100
Wire Wire Line
	3275 7000 3275 6900
Wire Wire Line
	3275 7000 3275 7100
Connection ~ 3275 7000
Connection ~ 3275 7100
Wire Wire Line
	3275 6900 3275 5775
Connection ~ 3275 6900
Wire Wire Line
	3275 5775 7575 5775
Wire Wire Line
	7575 5775 7575 6800
Wire Wire Line
	7575 6800 7225 6800
Wire Wire Line
	4050 6025 4200 6025
Wire Wire Line
	4350 6025 4500 6025
Connection ~ 4500 6025
Wire Wire Line
	4350 6025 4200 6025
Connection ~ 4350 6025
Connection ~ 4200 6025
Wire Wire Line
	7550 6025 7550 6700
Connection ~ 7550 6700
Wire Wire Line
	7550 6700 8125 6700
Wire Wire Line
	9950 5625 10225 5625
Wire Wire Line
	10225 5625 10225 5125
Wire Wire Line
	10475 5125 10225 5125
Connection ~ 10225 5125
Wire Wire Line
	10225 5125 10225 4750
Wire Wire Line
	11075 5125 11075 6800
Wire Wire Line
	11075 6800 11025 6800
Connection ~ 11025 6800
Wire Wire Line
	10225 4450 10025 4450
Wire Wire Line
	10025 4450 10025 5825
$Comp
L Device:Buzzer BZ1
U 1 1 663737AA
P 3950 8225
F 0 "BZ1" H 3955 8515 50  0000 C CNN
F 1 "Buzzer" H 3955 8424 50  0000 C CNN
F 2 "custom:buzer" V 3925 8325 50  0001 C CNN
F 3 "~" V 3925 8325 50  0001 C CNN
	1    3950 8225
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4050 8125 4500 8125
Wire Wire Line
	4500 8125 4500 7500
Wire Wire Line
	4500 7500 5025 7500
Wire Wire Line
	4050 8325 4300 8325
Connection ~ 4050 6025
Wire Wire Line
	2900 8475 4300 8475
Wire Wire Line
	4300 8475 4300 8325
Wire Wire Line
	2900 6025 2900 8475
$Comp
L miniimu-9_v6:miniIMU-9_v6 U1
U 1 1 663B967A
P 7050 4650
F 0 "U1" H 7528 4538 50  0000 L CNN
F 1 "miniIMU-9_v6" H 7528 4447 50  0000 L CNN
F 2 "custom:miniIMU-9_v6" H 7050 5100 50  0001 C CNN
F 3 "" H 7050 5100 50  0001 C CNN
	1    7050 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 5250 7150 5550
Wire Wire Line
	7150 5550 7275 5550
Wire Wire Line
	7275 5550 7275 6025
Connection ~ 7275 6025
Wire Wire Line
	7275 6025 7550 6025
Wire Wire Line
	7675 6600 7675 5500
Wire Wire Line
	7675 5500 7250 5500
Wire Wire Line
	7250 5500 7250 5250
Connection ~ 7675 6600
Wire Wire Line
	7675 6600 8150 6600
Wire Wire Line
	7050 5250 7050 6175
Wire Wire Line
	7050 6175 7425 6175
Wire Wire Line
	7425 6175 7425 7400
Connection ~ 7425 7400
Wire Wire Line
	7350 7300 7350 6250
Wire Wire Line
	7350 6250 6950 6250
Wire Wire Line
	6950 6250 6950 5250
Connection ~ 7350 7300
Text GLabel 1300 10175 0    50   Input ~ 0
A
Text GLabel 1300 10075 0    50   Input ~ 0
B
Wire Wire Line
	950  10175 4800 10175
Wire Wire Line
	4800 10175 4800 8100
Wire Wire Line
	5025 7600 4775 7600
Wire Wire Line
	4775 7600 4775 10075
Wire Wire Line
	4775 10075 950  10075
Wire Wire Line
	8125 6700 8350 6700
Connection ~ 8125 6700
Wire Wire Line
	8350 2350 8350 6700
Connection ~ 8350 2350
Wire Wire Line
	8200 2375 8200 3875
Wire Wire Line
	8200 5825 8700 5825
Connection ~ 8200 2375
Connection ~ 8700 5825
Wire Wire Line
	5025 8100 4800 8100
Wire Wire Line
	7350 7300 8100 7300
Wire Wire Line
	7425 7400 8075 7400
$Comp
L Device:Battery xt60
U 1 1 6666BA64
P 1975 5125
F 0 "xt60" H 2083 5171 50  0000 L CNN
F 1 "Battery" H 2083 5080 50  0000 L CNN
F 2 "Connector_AMASS:AMASS_XT60-F_1x02_P7.20mm_Vertical" V 1975 5185 50  0001 C CNN
F 3 "https://eu.mouser.com/datasheet/2/813/xt60-2490175.pdf" V 1975 5185 50  0001 C CNN
	1    1975 5125
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery xt30
U 1 1 6666CC1A
P 1600 5125
F 0 "xt30" H 1708 5171 50  0000 L CNN
F 1 "Battery" H 1708 5080 50  0000 L CNN
F 2 "Connector_AMASS:AMASS_XT30U-F_1x02_P5.0mm_Vertical" V 1600 5185 50  0001 C CNN
F 3 "https://eu.mouser.com/ProductDetail/DFRobot/FIT0586?qs=w%2Fv1CP2dgqouWR8IxqIK1w%3D%3D" V 1600 5185 50  0001 C CNN
	1    1600 5125
	1    0    0    -1  
$EndComp
$Comp
L cc6-1203sr-e:CC6-1203SR-E 3V3_converter1
U 1 1 66680960
P 2600 4300
F 0 "3V3_converter1" H 3300 4565 50  0000 C CNN
F 1 "CC6-1203SR-E" H 3300 4474 50  0000 C CNN
F 2 "custom:CC60512SRE" H 3850 4400 50  0001 L CNN
F 3 "https://product.tdk.com/system/files/dam/doc/product/power/switching-power/dc-dc-converter/catalog/cc-e_e.pdf" H 3850 4300 50  0001 L CNN
F 4 "DC-DC Converters, On-board type, Output: 3.96W, 3.3V, Isolated type, Option: SMD type" H 3850 4200 50  0001 L CNN "Description"
F 5 "8.8" H 3850 4100 50  0001 L CNN "Height"
F 6 "TDK" H 3850 4000 50  0001 L CNN "Manufacturer_Name"
F 7 "CC6-1203SR-E" H 3850 3900 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "967-CC6-1203SR-E" H 3850 3800 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TDK-Lambda/CC6-1203SR-E?qs=Vwh6e7toGLi4J%2FzloL2n3g%3D%3D" H 3850 3700 50  0001 L CNN "Mouser Price/Stock"
F 10 "CC6-1203SR-E" H 3850 3600 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/cc6-1203sr-e/tdk-lambda-americas?region=nac" H 3850 3500 50  0001 L CNN "Arrow Price/Stock"
	1    2600 4300
	1    0    0    -1  
$EndComp
$Comp
L sftn01m-05n:SFTN01M-05N 5V_converter1
U 1 1 66681E5D
P 2625 4825
F 0 "5V_converter1" H 3275 5090 50  0000 C CNN
F 1 "SFTN01M-05N" H 3275 4999 50  0000 C CNN
F 2 "custom:SFTN01M05N" H 3775 4925 50  0001 L CNN
F 3 "https://www.meanwell.com/webapp/product/search.aspx?prod=SFTN01-N" H 3775 4825 50  0001 L CNN
F 4 "Isolated DC/DC Converters - SMD 1W 12Vin 5Vout 20-200mA SMT Unregulated" H 3775 4725 50  0001 L CNN "Description"
F 5 "7.6" H 3775 4625 50  0001 L CNN "Height"
F 6 "Mean Well" H 3775 4525 50  0001 L CNN "Manufacturer_Name"
F 7 "SFTN01M-05N" H 3775 4425 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "709-SFTN01M-05N" H 3775 4325 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/MEAN-WELL/SFTN01M-05N?qs=A6eO%252BMLsxmQLvWwJN5Fn%252BQ%3D%3D" H 3775 4225 50  0001 L CNN "Mouser Price/Stock"
	1    2625 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	1975 5325 1600 5325
Wire Wire Line
	1975 5325 2300 5325
Wire Wire Line
	2300 5325 2300 4825
Wire Wire Line
	2300 4825 2625 4825
Connection ~ 1975 5325
Wire Wire Line
	1975 4925 2625 4925
Connection ~ 1975 4925
Wire Wire Line
	2300 4825 2300 4500
Wire Wire Line
	2300 4500 2600 4500
Connection ~ 2300 4825
Wire Wire Line
	1975 4925 1975 4300
Wire Wire Line
	1975 4300 2600 4300
Wire Wire Line
	4000 4300 4550 4300
Wire Wire Line
	4550 4300 4550 3875
Wire Wire Line
	4550 3875 8200 3875
Connection ~ 8200 3875
Wire Wire Line
	8200 3875 8200 5825
Connection ~ 10025 5825
Wire Wire Line
	8350 6700 10025 6700
Connection ~ 8350 6700
Connection ~ 10025 6700
Wire Wire Line
	10025 6700 10025 9000
Wire Wire Line
	7250 5500 4225 5500
Wire Wire Line
	4225 5500 4225 5125
Wire Wire Line
	4225 5125 3925 5125
Connection ~ 7250 5500
Wire Wire Line
	2625 5125 2525 5125
Wire Wire Line
	2525 5625 3750 5625
Wire Wire Line
	4125 5625 4125 4500
Wire Wire Line
	4125 4500 4000 4500
Wire Wire Line
	3750 5625 3750 6025
Wire Wire Line
	2900 6025 3750 6025
Connection ~ 3750 5625
Wire Wire Line
	3750 5625 4125 5625
Connection ~ 3750 6025
Wire Wire Line
	3750 6025 4050 6025
Wire Wire Line
	10325 8700 10325 8600
Wire Wire Line
	10325 8600 10325 8500
Connection ~ 10325 8600
Wire Wire Line
	10325 8700 10325 9000
Wire Wire Line
	10025 9000 10325 9000
Connection ~ 10325 8700
Connection ~ 10325 9000
Wire Wire Line
	10325 9000 11025 9000
$Comp
L Connector:Conn_01x10_Female pcb_conn1
U 1 1 6667319C
P 750 10575
F 0 "pcb_conn1" H 642 9850 50  0000 C CNN
F 1 "Conn_01x10_Female" H 642 9941 50  0000 C CNN
F 2 "custom:10connect" H 750 10575 50  0001 C CNN
F 3 "~" H 750 10575 50  0001 C CNN
	1    750  10575
	-1   0    0    1   
$EndComp
Wire Wire Line
	9600 6275 10025 6275
Wire Wire Line
	10025 5825 10025 6275
Connection ~ 10025 6275
Wire Wire Line
	10025 6275 10025 6700
$Comp
L teensy:Teensy4.1 control_board1
U 1 1 66362D60
P 6125 8750
F 0 "control_board1" H 6125 11315 50  0000 C CNN
F 1 "Teensy4.1" H 6125 11224 50  0000 C CNN
F 2 "teensy:Teensy41" H 5725 9150 50  0001 C CNN
F 3 "" H 5725 9150 50  0001 C CNN
	1    6125 8750
	1    0    0    -1  
$EndComp
$Comp
L custom:screw_hole screwhoel1
U 1 1 667CF5AB
P 5150 4475
F 0 "screwhoel1" H 5208 4809 50  0000 L CNN
F 1 "screw_hole" H 5208 4718 50  0000 L CNN
F 2 "custom:screwhole" H 5150 4625 50  0001 C CNN
F 3 "" H 5150 4625 50  0001 C CNN
	1    5150 4475
	1    0    0    -1  
$EndComp
Wire Wire Line
	4125 4500 5150 4500
Wire Wire Line
	5150 4500 5150 4475
Connection ~ 4125 4500
$Comp
L Connector:Conn_01x10_Female extrapins1
U 1 1 66687DFB
P 1950 8950
F 0 "extrapins1" H 1842 8225 50  0000 C CNN
F 1 "Conn_01x10_Female" H 1842 8316 50  0000 C CNN
F 2 "custom:10connect" H 1950 8950 50  0001 C CNN
F 3 "~" H 1950 8950 50  0001 C CNN
	1    1950 8950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 10775 3450 8700
Wire Wire Line
	3450 8700 2725 8700
Wire Wire Line
	2725 8700 2725 8450
Wire Wire Line
	2725 8450 2150 8450
Connection ~ 3450 10775
Wire Wire Line
	3450 10775 950  10775
Wire Wire Line
	3400 10675 3400 8725
Wire Wire Line
	3400 8725 2700 8725
Wire Wire Line
	2700 8725 2700 8550
Wire Wire Line
	2700 8550 2150 8550
Connection ~ 3400 10675
Wire Wire Line
	3400 10675 950  10675
Wire Wire Line
	5025 8200 4600 8200
Wire Wire Line
	4600 8200 4600 8750
Wire Wire Line
	4600 8750 2675 8750
Wire Wire Line
	2675 8750 2675 8650
Wire Wire Line
	2675 8650 2150 8650
Wire Wire Line
	5025 8300 4625 8300
Wire Wire Line
	2150 8775 2150 8750
Wire Wire Line
	4625 8300 4625 8775
Wire Wire Line
	2150 8775 4625 8775
Wire Wire Line
	2150 8850 2775 8850
Wire Wire Line
	2775 8850 2775 10275
Connection ~ 2775 10275
Wire Wire Line
	2775 10275 9075 10275
Wire Wire Line
	2150 8950 2675 8950
Wire Wire Line
	2675 8950 2675 10875
Wire Wire Line
	950  10875 2675 10875
Connection ~ 2675 10875
Wire Wire Line
	2675 10875 8125 10875
Wire Wire Line
	2150 9050 2600 9050
Wire Wire Line
	2600 9050 2600 10975
Connection ~ 2600 10975
Wire Wire Line
	2600 10975 950  10975
Wire Wire Line
	950  10375 2525 10375
Wire Wire Line
	3800 10375 3800 8600
Wire Wire Line
	3800 8600 2825 8600
Wire Wire Line
	2825 8600 2825 5725
Wire Wire Line
	2825 5725 1325 5725
Wire Wire Line
	1325 5725 1325 4925
Wire Wire Line
	1325 4925 1600 4925
Connection ~ 1600 4925
Wire Wire Line
	1600 4925 1975 4925
Wire Wire Line
	2300 5325 2525 5325
Wire Wire Line
	2525 5125 2525 5325
Connection ~ 2300 5325
Connection ~ 2525 5325
Wire Wire Line
	2525 5325 2525 5625
Text GLabel 1300 10375 0    50   Input ~ 0
12V
Wire Wire Line
	2525 10375 2525 9150
Wire Wire Line
	2525 9150 2150 9150
Connection ~ 2525 10375
Wire Wire Line
	2525 10375 3800 10375
Text GLabel 2325 8450 0    50   Input ~ 0
scl
Text GLabel 2350 8550 0    50   Input ~ 0
sda
Text GLabel 2325 8650 0    50   Input ~ 0
25
Text GLabel 2325 8775 0    50   Input ~ 0
26
Text GLabel 2350 8850 0    50   Input ~ 0
3v3
Text GLabel 2350 8950 0    50   Input ~ 0
gnd
Text GLabel 2350 9050 0    50   Input ~ 0
5v
Text GLabel 2350 9150 0    50   Input ~ 0
12v
Wire Wire Line
	2150 9250 4650 9250
Wire Wire Line
	4650 9250 4650 8400
Wire Wire Line
	4650 8400 5025 8400
Wire Wire Line
	5025 8500 4675 8500
Wire Wire Line
	4675 8500 4675 9275
Wire Wire Line
	4675 9275 2450 9275
Wire Wire Line
	2450 9275 2450 9350
Wire Wire Line
	2450 9350 2150 9350
Text GLabel 2350 9250 0    50   Input ~ 0
27
Text GLabel 2350 9350 0    50   Input ~ 0
28
$Comp
L Switch:SW_DIP_x01 pwr_sw1
U 1 1 66829A54
P 2400 3850
F 0 "pwr_sw1" H 2400 3583 50  0000 C CNN
F 1 "SW_DIP_x01" H 2400 3674 50  0000 C CNN
F 2 "custom:dipswitch1" H 2400 3850 50  0001 C CNN
F 3 "~" H 2400 3850 50  0001 C CNN
	1    2400 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 4500 2100 4500
Wire Wire Line
	2100 4500 2100 3850
Connection ~ 2300 4500
Wire Wire Line
	2600 4400 2525 4400
Wire Wire Line
	2525 4400 2525 4050
Wire Wire Line
	2525 4050 2700 4050
Wire Wire Line
	2700 4050 2700 3850
Wire Wire Line
	8075 7400 8825 7400
Wire Wire Line
	8825 7400 8825 7100
Connection ~ 8075 7400
Wire Wire Line
	8275 7200 8275 7300
Wire Wire Line
	8275 7300 8100 7300
Connection ~ 8100 7300
Wire Wire Line
	8275 7200 10325 7200
Wire Wire Line
	8825 7100 10325 7100
$Comp
L Switch:SW_DIP_x04 SW1
U 1 1 666FC3F3
P 3575 7100
F 0 "SW1" H 3575 7567 50  0000 C CNN
F 1 "SW_DIP_x04" H 3575 7476 50  0000 C CNN
F 2 "custom:dipswitch4" H 3575 7100 50  0001 C CNN
F 3 "~" H 3575 7100 50  0001 C CNN
	1    3575 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 6025 7275 6025
Wire Wire Line
	4925 6700 4925 5350
Wire Wire Line
	4925 5350 8550 5350
Wire Wire Line
	8550 5350 8550 5525
Wire Wire Line
	8550 5525 8750 5525
Wire Wire Line
	4925 6700 5025 6700
Wire Wire Line
	8750 5625 8525 5625
Wire Wire Line
	8525 5625 8525 5375
Wire Wire Line
	8525 5375 4950 5375
Wire Wire Line
	4950 5375 4950 6800
Wire Wire Line
	4950 6800 5025 6800
$EndSCHEMATC
