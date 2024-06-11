EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L pololu_motor:pololu_motor motor1
U 1 1 66360D6F
P 2225 1725
F 0 "motor1" H 2225 2460 50  0000 C CNN
F 1 "pololu_motor" H 2225 2369 50  0000 C CNN
F 2 "custom:pololu_motor" H 2225 2475 50  0001 C CNN
F 3 "" H 2225 2475 50  0001 C CNN
	1    2225 1725
	1    0    0    -1  
$EndComp
$Comp
L pololu_motor:pololu_motor motor2
U 1 1 66361689
P 4025 1725
F 0 "motor2" H 4025 2460 50  0000 C CNN
F 1 "pololu_motor" H 4025 2369 50  0000 C CNN
F 2 "custom:pololu_motor" H 4025 2475 50  0001 C CNN
F 3 "" H 4025 2475 50  0001 C CNN
	1    4025 1725
	1    0    0    -1  
$EndComp
$Comp
L pololu_motor:pololu_motor motor3
U 1 1 663619F7
P 5750 1725
F 0 "motor3" H 5750 2460 50  0000 C CNN
F 1 "pololu_motor" H 5750 2369 50  0000 C CNN
F 2 "custom:pololu_motor" H 5750 2475 50  0001 C CNN
F 3 "" H 5750 2475 50  0001 C CNN
	1    5750 1725
	1    0    0    -1  
$EndComp
Wire Wire Line
	2125 3975 1625 3975
Wire Wire Line
	1625 3975 1625 1725
Wire Wire Line
	2225 3975 2825 3975
Wire Wire Line
	2825 3975 2825 1725
Wire Wire Line
	3775 4150 3775 3975
Wire Wire Line
	3775 3975 3425 3975
Wire Wire Line
	3425 3975 3425 1725
Wire Wire Line
	3875 4150 3875 3975
Wire Wire Line
	3875 3975 4625 3975
Wire Wire Line
	4625 3975 4625 1725
Wire Wire Line
	5450 4150 5450 3975
Wire Wire Line
	5150 3975 5150 1725
Wire Wire Line
	5550 4150 5550 3975
Wire Wire Line
	5550 3975 6350 3975
Wire Wire Line
	6350 3975 6350 1725
Wire Wire Line
	3975 4150 3975 4125
Wire Wire Line
	5650 4125 5650 4150
Wire Wire Line
	4075 4050 4075 4150
Wire Wire Line
	5750 4050 5750 4150
Wire Wire Line
	1400 4125 1400 4650
Wire Wire Line
	975  4050 975  6850
Wire Wire Line
	975  6850 1400 6850
Wire Wire Line
	3075 5950 1400 5950
$Comp
L tcs3472_color_sensor:tcs3472_color_sensor kleur_sensor_1
U 1 1 66382B7A
P 7600 5000
F 0 "kleur_sensor_1" H 7650 6015 50  0000 C CNN
F 1 "tcs3472_color_sensor" H 7650 5924 50  0000 C CNN
F 2 "custom:tcs3472" H 7650 6100 50  0001 C CNN
F 3 "" H 7650 6100 50  0001 C CNN
	1    7600 5000
	1    0    0    -1  
$EndComp
$Comp
L tcs3472_color_sensor:tcs3472_color_sensor kleur_sensor_2
U 1 1 6638428B
P 7600 6075
F 0 "kleur_sensor_2" H 7650 7090 50  0000 C CNN
F 1 "tcs3472_color_sensor" H 7650 6999 50  0000 C CNN
F 2 "custom:tcs3472" H 7650 7175 50  0001 C CNN
F 3 "" H 7650 7175 50  0001 C CNN
	1    7600 6075
	1    0    0    -1  
$EndComp
$Comp
L tcs3472_color_sensor:tcs3472_color_sensor kleur_sensor_3
U 1 1 6638AC73
P 7600 7150
F 0 "kleur_sensor_3" H 7650 8165 50  0000 C CNN
F 1 "tcs3472_color_sensor" H 7650 8074 50  0000 C CNN
F 2 "custom:tcs3472" H 7650 8250 50  0001 C CNN
F 3 "" H 7650 8250 50  0001 C CNN
	1    7600 7150
	1    0    0    -1  
$EndComp
$Comp
L tcs3472_color_sensor:tcs3472_color_sensor kleur_sensor_4
U 1 1 6638E0E4
P 7600 8225
F 0 "kleur_sensor_4" H 7650 9240 50  0000 C CNN
F 1 "tcs3472_color_sensor" H 7650 9149 50  0000 C CNN
F 2 "custom:tcs3472" H 7650 9325 50  0001 C CNN
F 3 "" H 7650 9325 50  0001 C CNN
	1    7600 8225
	1    0    0    -1  
$EndComp
$Comp
L tcs3472_color_sensor:tcs3472_color_sensor kleur_sensor_5
U 1 1 6638E0EA
P 7600 9300
F 0 "kleur_sensor_5" H 7650 10315 50  0000 C CNN
F 1 "tcs3472_color_sensor" H 7650 10224 50  0000 C CNN
F 2 "custom:tcs3472" H 7650 10400 50  0001 C CNN
F 3 "" H 7650 10400 50  0001 C CNN
	1    7600 9300
	1    0    0    -1  
$EndComp
$Comp
L tcs3472_color_sensor:tcs3472_color_sensor kleur_sensor_6
U 1 1 6638E0F0
P 7600 10375
F 0 "kleur_sensor_6" H 7650 11390 50  0000 C CNN
F 1 "tcs3472_color_sensor" H 7650 11299 50  0000 C CNN
F 2 "custom:tcs3472" H 7650 11475 50  0001 C CNN
F 3 "" H 7650 11475 50  0001 C CNN
	1    7600 10375
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 9725 7100 9725
Wire Wire Line
	7100 9725 7100 8650
Wire Wire Line
	7100 8650 7350 8650
Wire Wire Line
	7100 8650 7100 8150
Wire Wire Line
	7100 7575 7350 7575
Connection ~ 7100 8650
Wire Wire Line
	7100 7575 7100 6500
Wire Wire Line
	7100 6500 7350 6500
Connection ~ 7100 7575
Wire Wire Line
	7100 6500 7100 5425
Wire Wire Line
	7100 5425 7350 5425
Connection ~ 7100 6500
Wire Wire Line
	7100 5425 7100 5225
Wire Wire Line
	7100 4350 7350 4350
Connection ~ 7100 5425
Wire Wire Line
	7350 4250 7075 4250
Wire Wire Line
	7075 4250 7075 5175
Wire Wire Line
	7075 5325 7350 5325
Wire Wire Line
	7075 5325 7075 6400
Wire Wire Line
	7075 6400 7350 6400
Connection ~ 7075 5325
Wire Wire Line
	7075 6400 7075 7475
Wire Wire Line
	7075 7475 7350 7475
Connection ~ 7075 6400
Wire Wire Line
	7075 7475 7075 8100
Wire Wire Line
	7075 8550 7350 8550
Connection ~ 7075 7475
Wire Wire Line
	7075 8550 7075 9625
Wire Wire Line
	7075 9625 7350 9625
Connection ~ 7075 8550
$Comp
L Interface_Expansion:MCP23017_SP port_multiplexer_2
U 1 1 663ADEC8
P 5725 6250
F 0 "port_multiplexer_2" V 5771 5106 50  0000 R CNN
F 1 "MCP23017_SP" V 5680 5106 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5925 5250 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001952C.pdf" H 5925 5150 50  0001 L CNN
	1    5725 6250
	0    -1   -1   0   
$EndComp
$Comp
L Interface_Expansion:PCA9548ADB i2c_multiplexer1
U 1 1 663C2FAA
P 10075 7525
F 0 "i2c_multiplexer1" H 10075 8606 50  0000 C CNN
F 1 "PCA9548ADB" H 10075 8515 50  0000 C CNN
F 2 "Package_SO:SSOP-24_5.3x8.2mm_P0.65mm" H 10075 6525 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/pca9548a.pdf" H 10125 7775 50  0001 C CNN
	1    10075 7525
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7950 4250 9025 4250
Wire Wire Line
	9025 4250 9025 6825
Wire Wire Line
	9025 6825 9675 6825
Wire Wire Line
	9675 6925 9000 6925
Wire Wire Line
	9000 6925 9000 4350
Wire Wire Line
	9000 4350 7950 4350
Wire Wire Line
	7950 5325 8975 5325
Wire Wire Line
	8975 5325 8975 7025
Wire Wire Line
	8975 7025 9675 7025
Wire Wire Line
	9675 7125 8950 7125
Wire Wire Line
	8950 7125 8950 5425
Wire Wire Line
	8950 5425 7950 5425
Wire Wire Line
	7950 6400 8925 6400
Wire Wire Line
	8925 6400 8925 7225
Wire Wire Line
	8925 7225 9675 7225
Wire Wire Line
	9675 7325 8900 7325
Wire Wire Line
	8900 7325 8900 6500
Wire Wire Line
	8900 6500 7950 6500
Wire Wire Line
	7950 7475 8900 7475
Wire Wire Line
	8900 7475 8900 7425
Wire Wire Line
	8900 7425 9675 7425
Wire Wire Line
	9675 7525 8925 7525
Wire Wire Line
	8925 7525 8925 7575
Wire Wire Line
	8925 7575 7950 7575
Wire Wire Line
	9675 7625 8950 7625
Wire Wire Line
	8950 7625 8950 8550
Wire Wire Line
	8950 8550 7950 8550
Wire Wire Line
	7950 8650 8975 8650
Wire Wire Line
	8975 8650 8975 7725
Wire Wire Line
	8975 7725 9675 7725
Wire Wire Line
	9675 7825 9000 7825
Wire Wire Line
	9000 7825 9000 9625
Wire Wire Line
	9000 9625 7950 9625
Wire Wire Line
	7950 9725 9025 9725
Wire Wire Line
	9025 9725 9025 7925
Wire Wire Line
	9025 7925 9675 7925
Text GLabel 1250 10575 0    50   Input ~ 0
sc6
Text GLabel 1250 10675 0    50   Input ~ 0
sd6
Wire Wire Line
	10875 6925 10475 6925
Wire Wire Line
	10475 6825 11025 6825
Wire Wire Line
	11025 6825 11025 10875
Text GLabel 1250 10775 0    50   Input ~ 0
sda
Text GLabel 1250 10875 0    50   Input ~ 0
scl
Wire Wire Line
	2975 7900 2975 10975
Wire Wire Line
	2975 10975 950  10975
Wire Wire Line
	10875 10775 10875 6925
Text GLabel 1250 10975 0    50   Input ~ 0
gnd
Text GLabel 1250 11075 0    50   Input ~ 0
5v
Wire Wire Line
	4675 11075 4675 8350
Wire Wire Line
	950  11075 4675 11075
Text GLabel 1250 10375 0    50   Input ~ 0
3.3v
Wire Wire Line
	950  10375 4775 10375
Wire Wire Line
	4625 7050 5025 7050
Wire Wire Line
	5025 7050 5025 7200
Wire Wire Line
	4625 6850 4625 6250
Wire Wire Line
	6825 6250 6825 7200
Wire Wire Line
	6825 7200 6525 7200
Connection ~ 5025 7200
Wire Wire Line
	5025 7200 5025 8150
Wire Wire Line
	4625 6850 4775 6850
Wire Wire Line
	4775 6850 4775 8100
Wire Wire Line
	1975 5150 1975 5550
Wire Wire Line
	1975 5550 4925 5550
Wire Wire Line
	2075 5150 2075 5525
Wire Wire Line
	2075 5525 5025 5525
Wire Wire Line
	5025 5525 5025 5550
Wire Wire Line
	5125 5550 5125 5500
Wire Wire Line
	5125 5500 2175 5500
Wire Wire Line
	2175 5500 2175 5150
Wire Wire Line
	2275 5150 2275 5475
Wire Wire Line
	2275 5475 5225 5475
Wire Wire Line
	5225 5475 5225 5550
Wire Wire Line
	3625 5150 3625 5450
Wire Wire Line
	3625 5450 5325 5450
Wire Wire Line
	5325 5450 5325 5550
Wire Wire Line
	5425 5550 5425 5425
Wire Wire Line
	5425 5425 3725 5425
Wire Wire Line
	3725 5425 3725 5150
Wire Wire Line
	3825 5150 3825 5400
Wire Wire Line
	3825 5400 5525 5400
Wire Wire Line
	5525 5400 5525 5550
Wire Wire Line
	5625 5550 5625 5375
Wire Wire Line
	5625 5375 3925 5375
Wire Wire Line
	3925 5375 3925 5150
Wire Wire Line
	5300 5150 5300 5350
Wire Wire Line
	5300 5350 5825 5350
Wire Wire Line
	5825 5350 5825 5550
Wire Wire Line
	5400 5150 5400 5325
Wire Wire Line
	5400 5325 5925 5325
Wire Wire Line
	5925 5325 5925 5550
Wire Wire Line
	5500 5150 5500 5300
Wire Wire Line
	5500 5300 6025 5300
Wire Wire Line
	6025 5300 6025 5550
Wire Wire Line
	6125 5550 6125 5275
Wire Wire Line
	6125 5275 5600 5275
Wire Wire Line
	5600 5275 5600 5150
Wire Wire Line
	5800 5150 5800 5175
Wire Wire Line
	5800 5175 4125 5175
Wire Wire Line
	4125 5175 4125 5150
Wire Wire Line
	4125 5175 2475 5175
Wire Wire Line
	2475 5175 2475 5150
Connection ~ 4125 5175
Wire Wire Line
	2575 5150 2575 5225
Wire Wire Line
	2575 5225 4225 5225
Wire Wire Line
	4225 5225 4225 5150
Wire Wire Line
	4225 5225 5900 5225
Wire Wire Line
	5900 5225 5900 5150
Connection ~ 4225 5225
Wire Wire Line
	5900 5225 7100 5225
Connection ~ 5900 5225
Connection ~ 7100 5225
Wire Wire Line
	7100 5225 7100 4350
Wire Wire Line
	5800 5175 7075 5175
Connection ~ 5800 5175
Connection ~ 7075 5175
Wire Wire Line
	7075 5175 7075 5325
Wire Wire Line
	4775 8100 6400 8100
Connection ~ 4775 8100
Wire Wire Line
	4775 8100 4775 10375
Connection ~ 7075 8100
Wire Wire Line
	7075 8100 7075 8550
Wire Wire Line
	7100 8150 5025 8150
Connection ~ 7100 8150
Wire Wire Line
	7100 8150 7100 7575
Wire Wire Line
	10075 4000 10075 6625
Wire Wire Line
	10075 8525 10075 10550
Wire Wire Line
	7100 10550 7100 9725
Connection ~ 7100 9725
Wire Wire Line
	7075 4250 7075 4000
Wire Wire Line
	7075 4000 10075 4000
Connection ~ 7075 4250
Wire Wire Line
	6225 5550 6225 3700
Wire Wire Line
	6225 3700 2125 3700
Wire Wire Line
	2125 3700 2125 2775
Wire Wire Line
	2275 2775 2275 3675
Wire Wire Line
	2275 3675 6325 3675
Wire Wire Line
	6325 3675 6325 5550
Wire Wire Line
	6425 5550 6425 3650
Wire Wire Line
	6425 3650 3925 3650
Wire Wire Line
	3925 3650 3925 2775
Wire Wire Line
	4075 2775 4075 3625
Wire Wire Line
	4075 3625 6525 3625
Wire Wire Line
	6525 3625 6525 5550
Text GLabel 1250 10275 0    50   Input ~ 0
A
Wire Wire Line
	6925 10275 6925 3150
Wire Wire Line
	6925 3150 5650 3150
Wire Wire Line
	5650 3150 5650 2775
Wire Wire Line
	950  10275 6925 10275
Wire Wire Line
	5800 2775 5800 3125
Wire Wire Line
	5800 3125 6950 3125
Wire Wire Line
	6950 3125 6950 10175
Wire Wire Line
	6950 10175 950  10175
Text GLabel 1250 10175 0    50   Input ~ 0
B
Wire Wire Line
	1975 2775 1975 3025
Wire Wire Line
	1975 3025 3775 3025
Wire Wire Line
	3775 3025 3775 2775
Wire Wire Line
	3775 3025 5500 3025
Wire Wire Line
	5500 3025 5500 2775
Connection ~ 3775 3025
Wire Wire Line
	5950 2775 5950 2975
Wire Wire Line
	5950 2975 4225 2975
Wire Wire Line
	4225 2975 4225 2775
Wire Wire Line
	4225 2975 2425 2975
Wire Wire Line
	2425 2975 2425 2775
Connection ~ 4225 2975
Wire Wire Line
	2975 7900 875  7900
Wire Wire Line
	875  7900 875  2975
Wire Wire Line
	875  2975 2425 2975
Connection ~ 2975 7900
Connection ~ 2425 2975
Wire Wire Line
	1975 3025 900  3025
Wire Wire Line
	900  3025 900  8350
Wire Wire Line
	900  8350 4675 8350
Connection ~ 1975 3025
Text GLabel 1250 10475 0    50   Input ~ 0
12v
$Comp
L Connector:Conn_01x10_Female J1
U 1 1 66673A65
P 750 10675
F 0 "J1" H 642 9950 50  0000 C CNN
F 1 "Conn_01x10_Female" H 642 10041 50  0000 C CNN
F 2 "custom:10x_conn" H 750 10675 50  0001 C CNN
F 3 "~" H 750 10675 50  0001 C CNN
	1    750  10675
	-1   0    0    1   
$EndComp
Wire Wire Line
	1400 10475 1400 6850
Wire Wire Line
	950  10475 1400 10475
Wire Wire Line
	3725 7900 3725 7600
Wire Wire Line
	3075 7600 3725 7600
Wire Wire Line
	2975 7900 3725 7900
Wire Wire Line
	3725 7600 4625 7600
Wire Wire Line
	4625 7600 4625 7050
Connection ~ 3725 7600
Wire Wire Line
	3075 5950 3075 7600
Wire Wire Line
	6325 6950 6325 7200
Connection ~ 6325 7200
Wire Wire Line
	6325 7200 5025 7200
Wire Wire Line
	6525 6950 6525 7200
Connection ~ 6525 7200
Wire Wire Line
	6525 7200 6325 7200
$Comp
L Device:R i2c_res1
U 1 1 666C9452
P 6400 7475
F 0 "i2c_res1" H 6470 7521 50  0000 L CNN
F 1 "R" H 6470 7430 50  0000 L CNN
F 2 "custom:resistor" V 6330 7475 50  0001 C CNN
F 3 "~" H 6400 7475 50  0001 C CNN
	1    6400 7475
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 8100 6400 7625
Connection ~ 6400 8100
Wire Wire Line
	6400 8100 7075 8100
Wire Wire Line
	6400 7325 6400 6950
Wire Wire Line
	6400 6950 6425 6950
Wire Wire Line
	4925 6950 4925 10775
Wire Wire Line
	950  10775 4925 10775
Connection ~ 4925 10775
Wire Wire Line
	4925 10775 10875 10775
Wire Wire Line
	5025 6950 4975 6950
Wire Wire Line
	4975 6950 4975 10875
Wire Wire Line
	950  10875 4975 10875
Connection ~ 4975 10875
Wire Wire Line
	4975 10875 11025 10875
Wire Wire Line
	10475 7825 10475 7925
Wire Wire Line
	10475 7925 10475 8025
Connection ~ 10475 7925
Wire Wire Line
	10475 8025 10475 10550
Wire Wire Line
	10475 10550 10075 10550
Connection ~ 10475 8025
Connection ~ 10075 10550
Wire Wire Line
	5450 3975 5150 3975
Connection ~ 4075 4050
Wire Wire Line
	4075 4050 5750 4050
Connection ~ 3975 4125
$Comp
L tb9051ftg:TB9051FTG motor_driver3
U 1 1 66365747
P 5800 4650
F 0 "motor_driver3" V 5754 4978 50  0000 L CNN
F 1 "TB9051FTG" V 5845 4978 50  0000 L CNN
F 2 "custom:TB9051FTG" H 5800 5100 50  0001 C CNN
F 3 "" H 5800 5100 50  0001 C CNN
	1    5800 4650
	0    1    1    0   
$EndComp
$Comp
L tb9051ftg:TB9051FTG motor_driver2
U 1 1 6636526D
P 4125 4650
F 0 "motor_driver2" V 4079 4978 50  0000 L CNN
F 1 "TB9051FTG" V 4170 4978 50  0000 L CNN
F 2 "custom:TB9051FTG" H 4125 5100 50  0001 C CNN
F 3 "" H 4125 5100 50  0001 C CNN
	1    4125 4650
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 4125 2325 4125
Wire Wire Line
	3975 4125 3225 4125
Connection ~ 2325 4125
Wire Wire Line
	2325 4125 2325 4150
Connection ~ 2425 4050
Wire Wire Line
	2425 4150 2425 4050
Wire Wire Line
	2225 4150 2225 3975
Wire Wire Line
	2125 4150 2125 3975
Wire Wire Line
	2425 4050 4075 4050
Wire Wire Line
	2425 4050 975  4050
$Comp
L tb9051ftg:TB9051FTG motor_driver1
U 1 1 66362316
P 2475 4650
F 0 "motor_driver1" V 2429 4978 50  0000 L CNN
F 1 "TB9051FTG" V 2520 4978 50  0000 L CNN
F 2 "custom:TB9051FTG" H 2475 5100 50  0001 C CNN
F 3 "" H 2475 5100 50  0001 C CNN
	1    2475 4650
	0    1    1    0   
$EndComp
Wire Wire Line
	10075 10550 8100 10550
Wire Wire Line
	8100 10175 7950 10175
Wire Wire Line
	8100 10175 8100 10550
Connection ~ 8100 10550
Wire Wire Line
	8100 10550 7100 10550
Wire Wire Line
	8100 10175 8100 9100
Wire Wire Line
	8100 9100 7950 9100
Connection ~ 8100 10175
Wire Wire Line
	8100 9100 8100 8025
Wire Wire Line
	8100 8025 7950 8025
Connection ~ 8100 9100
Wire Wire Line
	8100 8025 8100 6950
Wire Wire Line
	8100 6950 7950 6950
Connection ~ 8100 8025
Wire Wire Line
	8100 6950 8100 5875
Wire Wire Line
	8100 5875 7950 5875
Connection ~ 8100 6950
Wire Wire Line
	8100 5850 8100 4800
Wire Wire Line
	8100 4800 7950 4800
Wire Wire Line
	1575 4650 1400 4650
Connection ~ 1400 4650
Wire Wire Line
	1400 4650 1400 5950
Wire Wire Line
	3225 4650 3225 4125
Connection ~ 3225 4125
Wire Wire Line
	3225 4125 2325 4125
Wire Wire Line
	4900 4650 4900 4125
Wire Wire Line
	3975 4125 4900 4125
Connection ~ 4900 4125
Wire Wire Line
	4900 4125 5650 4125
$EndSCHEMATC
