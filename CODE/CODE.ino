#include <Wire.h>               //https://www.arduino.cc/reference/en/language/functions/communication/wire/
#include "Adafruit_TCS34725.h"  //https://github.com/adafruit/Adafruit_TCS34725
#include <Adafruit_MCP23X17.h>  //https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library/tree/master
#include <LIS3MDL.h>            //https://github.com/pololu/lis3mdl-arduino
#include <LSM6.h>               //https://github.com/pololu/lsm6-arduino
#include <TimerThree.h>         //https://www.arduino.cc/reference/en/libraries/timerthree/


const int minpulsbal = 1100;  //minimum pulses needed to be able to say it has the ball in posesion
double sp = 1200.000;         //estemate needed speed in RPM ~0-1800

//i2c addr
#define PCAADDR 0x70   //i2c address of the i2c multiplexer
#define mcp1ADDR 0x20  //first portmultiplexer for ir sensors
#define mcp2ADDR 0x22  //first portmultiplexer for motors

//IR sensors on multiplex1 0x20
#define ir1 0      // GPA0
#define ir2 1      // GPA1
#define ir3 2      // GPA2
#define ir4 3      // GPA3
#define ir5 4      // GPA4
#define ir6 5      // GPA5
#define ir7 6      // GPA6
#define ir8 7      // GPA7
#define ir9 8      // GPB0
#define ir10 9     // GPB1
#define ir11 10    // GPB2
#define ir12 11    // GPB3
#define ir13 12    // GPB4
#define ir14 13    // GPB5
#define ir15 14    // GPB6
#define ir16 15    // GPB7
#define irBALL 25  // IR sensor to see if we have the ball, teensy pin NO 25

//motors on multiplex2  0x22
#define ArrayElementCount(needRPM) (sizeof(needRPM) / sizeof(needRPM[0]))  //used to calculate array size
const int maxspeed = 1000;                                                 //max speed in PWM value
//calibration data
int Amotordata[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 1, 0, 1, 1, 1, 0, 14, 12, 14, 9, 11, 16, 9, 9, 9, 16, 28, 28, 32, 42, 39, 29, 29, 45, 36, 30, 60, 102, 109, 113, 124, 154, 153, 154, 151, 172, 183, 214, 243, 288, 302, 306, 320, 336, 337, 338, 356, 420, 438, 451, 465, 501, 499, 492, 509, 519, 528, 561, 567, 611, 632, 610, 616, 638, 641, 641,
                     667, 705, 721, 735, 724, 772, 756, 761, 748, 773, 774, 810, 817, 849, 840, 840, 861, 858, 876, 857, 883, 917, 917, 920, 932, 954, 936, 925, 918, 963, 951, 960, 995, 1011, 1011, 1008, 1011, 1052, 1022, 1033, 1014, 1059, 1059, 1092, 1053, 1092, 1080, 1056, 1062, 1097, 1111, 1096, 1094, 1170, 1131, 1137, 1134, 1158, 1174, 1137, 1185, 1234, 1198, 1203, 1192,
                     1223, 1194, 1207, 1204, 1241, 1222, 1252, 1229, 1291, 1232, 1241, 1226, 1246, 1244, 1225, 1230, 1298, 1295, 1271, 1270, 1306, 1300, 1280, 1265, 1357, 1283, 1278, 1307, 1369, 1297, 1337, 1299, 1357, 1326, 1326, 1316, 1375, 1341, 1373, 1366, 1351, 1366, 1326, 1314, 1404, 1364, 1373, 1366, 1417, 1431, 1381, 1349, 1468, 1383, 1367, 1352, 1460, 1411, 1420, 1400,
                     1471, 1435, 1415, 1429, 1455, 1424, 1432, 1406, 1506, 1447, 1444, 1416, 1511, 1438, 1442, 1476, 1578, 1498, 1444, 1440, 1521, 1539, 1448, 1448, 1539, 1492, 1518, 1464, 1604, 1565, 1503, 1468, 1539, 1479, 1492, 1481, 1582, 1549, 1495, 1525, 1618, 1543, 1515, 1546, 1631, 1597, 1532, 1569, 1712, 1577, 1537, 1557, 1621, 1596, 1532, 1546, 1721, 1572, 1566, 1562,
                     1645, 1602, 1592, 1580, 1708, 1587, 1587, 1599, 1639, 1566, 1576, 1540, 1699, 1664, 1561, 1593, 1731, 1589, 1613, 1563, 1695, 1608, 1628, 1597, 1721, 1737, 1613, 1613, 1772, 1665, 1670, 1656, 1758, 1645, 1649, 1603, 1772, 1702, 1688, 1678, 1782, 1685, 1718, 1650, 1863, 1793, 1687, 1717, 1804, 1782, 1695, 1704, 1789, 1769, 1674, 1715, 1867, 1795, 1675, 1702,
                     1761, 1673, 1676, 1667, 1765, 1708, 1721, 1667, 1792, 1728, 1681, 1674, 1792, 1770, 1745, 1698, 1816, 1797, 1715, 1776, 1938, 1796, 1742, 1745, 1911, 1832, 1800, 1772, 1930, 1752, 1721, 1714, 1920, 1805, 1730, 1711, 1864, 1862, 1700, 1762, 1897, 1805, 1753, 1761, 1951, 1790, 1749, 1773, 1947, 1781, 1712, 1782, 1901, 1799, 1732, 1724, 1856, 1772, 1759, 1751,
                     1923, 1846, 1765, 1765, 1944, 1822, 1791, 1776, 1945, 1854, 1830, 1800, 1921, 1860, 1776, 1748, 1954, 1874, 1858, 1773, 2035, 1852, 1775, 1826, 2072, 1934, 1859, 1897, 2003, 2054, 1860, 1887, 2214, 1993, 1970, 1874, 2041, 2043, 1894, 1839, 2080, 1905, 1822, 1907, 2124, 1935, 1857, 1883, 1957, 1940, 1860, 1870, 1865, 1877, 1876, 1846, 2092, 1928, 1825, 1833,
                     1979, 1914, 1920, 1837, 1988, 1900, 1867, 1825, 2049, 1964, 1834, 1857, 1979, 1893, 1815, 1874, 2002, 2023, 1803, 1877, 1894, 1989, 1840, 1846, 2001, 1958, 1861, 1867, 2066, 1952, 1853, 1806, 1894, 1880, 1769, 1767, 1893, 1840, 1780, 1787, 1857, 1814, 1780, 1722, 1859, 1920, 1800, 1840, 1853, 1823, 1776, 1771, 1843, 1871, 1819, 1769, 1900, 1876, 1792, 1809,
                     1908, 1944, 1859, 1920, 2073, 1985, 1913, 1917, 1940, 1897, 1883, 1807, 1910, 1910, 1873, 1826, 1917, 1893, 1802, 1802, 1886, 2008, 1859, 1814, 1930, 1905, 1850, 1833, 1909, 2019, 1850, 1807, 2012, 2010, 1938, 1856, 2051, 1890, 1848, 1842, 1958, 1950, 1874, 1915, 2029, 1947, 1827, 1867, 1949, 2022, 1957, 1941, 2161, 2040, 2018, 1894, 2005, 2118, 1986, 1951,
                     1936, 1927, 1946, 1978, 2025, 2019, 1888, 1904, 1964, 1914, 1822, 1834, 1945, 1924, 1873, 1853, 1995, 1975, 1830, 1894, 1958, 1958, 1848, 1786, 1907, 1959, 1952, 1964, 2020, 1927, 1901, 1903, 1986, 1931, 1921, 1985, 1972, 1993, 2028, 1859, 1927, 1901, 1904, 1861, 1936, 1937, 1928, 1902, 1937, 1971, 1944, 1840, 1948, 1972, 1955, 1942, 1972, 2073, 2057, 1924,
                     1925, 2036, 1893, 1836, 2008, 2060, 1947, 1957, 2156, 1976, 1905, 1914, 2022, 1985, 1947, 1920, 2058, 1968, 1893, 1929, 2042, 2052, 1975, 1867, 2063, 1962, 2011, 1948, 2070, 1957, 1911, 1843, 1944, 1945, 1902, 1878, 1964, 1864, 1930, 1870, 1942, 1958, 1941, 1898, 1898, 1923, 1948, 1921, 1957, 1934, 1952, 1924, 1942, 1901, 1950, 1894, 2016, 2062, 1975, 1893,
                     1921, 1978, 1935, 1857, 1955, 1921, 1866, 1841, 1890, 1876, 1821, 1855, 1961, 1895, 1877, 1852, 1873, 1857, 1915, 1820, 1850, 1897, 1856, 1833, 1921, 1915, 1823, 1807, 1904, 1830, 1817, 1790, 1911, 1864, 1883, 1843, 1915, 1989, 1917, 1863, 1921, 1951, 1958, 1971, 1958, 1983, 1901, 1934, 1934, 1987, 2011, 1979, 2023, 2059, 2026, 1890, 2052, 1931, 1917, 1923,
                     2126, 2036, 1965, 1899, 1971, 1913, 1870, 1835, 1911, 1962, 2005, 1971, 2039, 2050, 1986, 1857, 1993, 1958, 2041, 2025, 1969, 2004, 2012, 1931, 2101, 1939, 2006, 2063, 2035, 2146, 1971, 1972, 2018, 2028, 1917, 1835, 1923, 1988, 1884, 1924, 1947, 1894, 1968, 1952, 1931, 1909, 1914, 1883, 1901, 1933, 2001, 1952, 1992, 2019, 1938, 1952, 1921, 2009, 1999, 1982,
                     1985, 1949, 1907, 1968, 1911, 2006, 1935, 1944, 1921, 1924, 1981, 1930, 1928, 2046, 1877, 1811, 1888, 1912, 1866, 1887, 1918, 1929, 1913, 1922, 1923, 1915, 1918, 1918, 1937, 1981, 1948, 1959, 1978, 1972, 1981, 1920, 1994, 1995, 1987, 1890, 1929, 1985, 1978, 2042, 2070, 2006, 1999, 1948, 1961, 2046, 1971, 1984, 2097, 1942, 1937, 1887, 2011, 1999, 2016, 1979,
                     2008, 1992, 2034, 2003, 1988, 2052, 2025, 1931, 2030, 1952, 1900, 1878, 1930, 2038, 1954, 1941, 2003, 2013, 1992, 1920, 2005, 1957, 1960, 1911, 1931, 1954, 1927, 1935, 1971, 2023, 1931, 1900, 1962, 1952, 1979, 1941, 1957, 1985, 1944, 1961, 2029, 1998, 1995, 1946, 1955, 1949, 1938, 1921, 1908, 1941, 1943, 1932, 1948, 1924, 1989, 1974, 1977, 1994, 2033, 1948,
                     1907, 1948, 1880, 1915, 1941, 1921, 1949, 1938, 1958, 1956, 1937, 1931, 2032, 1996, 2008, 1937, 1937, 1935, 1962, 1941, 1938, 2029, 2013, 1999, 2021, 2029, 1899, 1886, 2013, 1871, 1853, 1901, 1860, 1907, 1880, 1910, 1943, 1881, 1893, 1873, 1870, 1908, 1917, 1908, 1904, 1895, 1854, 1889, 1900, 1857, 1934, 1873, 1936, 1920, 1900, 1903, 1925, 1910, 1886, 1924,
                     1891, 1905, 1883, 1854, 1918, 1860, 1912, 1879, 1913, 1898, 1905, 1874, 1893, 1870, 1910 };
int Bmotordata[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 1, 0, 1, 1, 1, 0, 14, 12, 14, 9, 11, 16, 9, 9, 9, 16, 28, 28, 32, 42, 39, 29, 29, 45, 36, 30, 60, 102, 109, 113, 124, 154, 153, 154, 151, 172, 183, 214, 243, 288, 302, 306, 320, 336, 337, 338, 356, 420, 438, 451, 465, 501, 499, 492, 509, 519, 528, 561, 567, 611, 632, 610, 616, 638, 641, 641, 667,
                     705, 721, 735, 724, 772, 756, 761, 748, 773, 774, 810, 817, 849, 840, 840, 861, 858, 876, 857, 883, 917, 917, 920, 932, 954, 936, 925, 918, 963, 951, 960, 995, 1011, 1011, 1008, 1011, 1052, 1022, 1033, 1014, 1059, 1059, 1092, 1053, 1092, 1080, 1056, 1062, 1097, 1111, 1096, 1094, 1170, 1131, 1137, 1134, 1158, 1174, 1137, 1185, 1234, 1198, 1203, 1192, 1223, 1194,
                     1207, 1204, 1241, 1222, 1252, 1229, 1291, 1232, 1241, 1226, 1246, 1244, 1225, 1230, 1298, 1295, 1271, 1270, 1306, 1300, 1280, 1265, 1357, 1283, 1278, 1307, 1369, 1297, 1337, 1299, 1357, 1326, 1326, 1316, 1375, 1341, 1373, 1366, 1351, 1366, 1326, 1314, 1404, 1364, 1373, 1366, 1417, 1431, 1381, 1349, 1468, 1383, 1367, 1352, 1460, 1411, 1420, 1400, 1471, 1435,
                     1415, 1429, 1455, 1424, 1432, 1406, 1506, 1447, 1444, 1416, 1511, 1438, 1442, 1476, 1578, 1498, 1444, 1440, 1521, 1539, 1448, 1448, 1539, 1492, 1518, 1464, 1604, 1565, 1503, 1468, 1539, 1479, 1492, 1481, 1582, 1549, 1495, 1525, 1618, 1543, 1515, 1546, 1631, 1597, 1532, 1569, 1712, 1577, 1537, 1557, 1621, 1596, 1532, 1546, 1721, 1572, 1566, 1562, 1645, 1602,
                     1592, 1580, 1708, 1587, 1587, 1599, 1639, 1566, 1576, 1540, 1699, 1664, 1561, 1593, 1731, 1589, 1613, 1563, 1695, 1608, 1628, 1597, 1721, 1737, 1613, 1613, 1772, 1665, 1670, 1656, 1758, 1645, 1649, 1603, 1772, 1702, 1688, 1678, 1782, 1685, 1718, 1650, 1863, 1793, 1687, 1717, 1804, 1782, 1695, 1704, 1789, 1769, 1674, 1715, 1867, 1795, 1675, 1702, 1761, 1673,
                     1676, 1667, 1765, 1708, 1721, 1667, 1792, 1728, 1681, 1674, 1792, 1770, 1745, 1698, 1816, 1797, 1715, 1776, 1938, 1796, 1742, 1745, 1911, 1832, 1800, 1772, 1930, 1752, 1721, 1714, 1920, 1805, 1730, 1711, 1864, 1862, 1700, 1762, 1897, 1805, 1753, 1761, 1951, 1790, 1749, 1773, 1947, 1781, 1712, 1782, 1901, 1799, 1732, 1724, 1856, 1772, 1759, 1751, 1923, 1846,
                     1765, 1765, 1944, 1822, 1791, 1776, 1945, 1854, 1830, 1800, 1921, 1860, 1776, 1748, 1954, 1874, 1858, 1773, 2035, 1852, 1775, 1826, 2072, 1934, 1859, 1897, 2003, 2054, 1860, 1887, 2214, 1993, 1970, 1874, 2041, 2043, 1894, 1839, 2080, 1905, 1822, 1907, 2124, 1935, 1857, 1883, 1957, 1940, 1860, 1870, 1865, 1877, 1876, 1846, 2092, 1928, 1825, 1833, 1979, 1914,
                     1920, 1837, 1988, 1900, 1867, 1825, 2049, 1964, 1834, 1857, 1979, 1893, 1815, 1874, 2002, 2023, 1803, 1877, 1894, 1989, 1840, 1846, 2001, 1958, 1861, 1867, 2066, 1952, 1853, 1806, 1894, 1880, 1769, 1767, 1893, 1840, 1780, 1787, 1857, 1814, 1780, 1722, 1859, 1920, 1800, 1840, 1853, 1823, 1776, 1771, 1843, 1871, 1819, 1769, 1900, 1876, 1792, 1809, 1908, 1944,
                     1859, 1920, 2073, 1985, 1913, 1917, 1940, 1897, 1883, 1807, 1910, 1910, 1873, 1826, 1917, 1893, 1802, 1802, 1886, 2008, 1859, 1814, 1930, 1905, 1850, 1833, 1909, 2019, 1850, 1807, 2012, 2010, 1938, 1856, 2051, 1890, 1848, 1842, 1958, 1950, 1874, 1915, 2029, 1947, 1827, 1867, 1949, 2022, 1957, 1941, 2161, 2040, 2018, 1894, 2005, 2118, 1986, 1951, 1936, 1927,
                     1946, 1978, 2025, 2019, 1888, 1904, 1964, 1914, 1822, 1834, 1945, 1924, 1873, 1853, 1995, 1975, 1830, 1894, 1958, 1958, 1848, 1786, 1907, 1959, 1952, 1964, 2020, 1927, 1901, 1903, 1986, 1931, 1921, 1985, 1972, 1993, 2028, 1859, 1927, 1901, 1904, 1861, 1936, 1937, 1928, 1902, 1937, 1971, 1944, 1840, 1948, 1972, 1955, 1942, 1972, 2073, 2057, 1924, 1925, 2036,
                     1893, 1836, 2008, 2060, 1947, 1957, 2156, 1976, 1905, 1914, 2022, 1985, 1947, 1920, 2058, 1968, 1893, 1929, 2042, 2052, 1975, 1867, 2063, 1962, 2011, 1948, 2070, 1957, 1911, 1843, 1944, 1945, 1902, 1878, 1964, 1864, 1930, 1870, 1942, 1958, 1941, 1898, 1898, 1923, 1948, 1921, 1957, 1934, 1952, 1924, 1942, 1901, 1950, 1894, 2016, 2062, 1975, 1893, 1921, 1978,
                     1935, 1857, 1955, 1921, 1866, 1841, 1890, 1876, 1821, 1855, 1961, 1895, 1877, 1852, 1873, 1857, 1915, 1820, 1850, 1897, 1856, 1833, 1921, 1915, 1823, 1807, 1904, 1830, 1817, 1790, 1911, 1864, 1883, 1843, 1915, 1989, 1917, 1863, 1921, 1951, 1958, 1971, 1958, 1983, 1901, 1934, 1934, 1987, 2011, 1979, 2023, 2059, 2026, 1890, 2052, 1931, 1917, 1923, 2126, 2036,
                     1965, 1899, 1971, 1913, 1870, 1835, 1911, 1962, 2005, 1971, 2039, 2050, 1986, 1857, 1993, 1958, 2041, 2025, 1969, 2004, 2012, 1931, 2101, 1939, 2006, 2063, 2035, 2146, 1971, 1972, 2018, 2028, 1917, 1835, 1923, 1988, 1884, 1924, 1947, 1894, 1968, 1952, 1931, 1909, 1914, 1883, 1901, 1933, 2001, 1952, 1992, 2019, 1938, 1952, 1921, 2009, 1999, 1982, 1985, 1949,
                     1907, 1968, 1911, 2006, 1935, 1944, 1921, 1924, 1981, 1930, 1928, 2046, 1877, 1811, 1888, 1912, 1866, 1887, 1918, 1929, 1913, 1922, 1923, 1915, 1918, 1918, 1937, 1981, 1948, 1959, 1978, 1972, 1981, 1920, 1994, 1995, 1987, 1890, 1929, 1985, 1978, 2042, 2070, 2006, 1999, 1948, 1961, 2046, 1971, 1984, 2097, 1942, 1937, 1887, 2011, 1999, 2016, 1979, 2008, 1992,
                     2034, 2003, 1988, 2052, 2025, 1931, 2030, 1952, 1900, 1878, 1930, 2038, 1954, 1941, 2003, 2013, 1992, 1920, 2005, 1957, 1960, 1911, 1931, 1954, 1927, 1935, 1971, 2023, 1931, 1900, 1962, 1952, 1979, 1941, 1957, 1985, 1944, 1961, 2029, 1998, 1995, 1946, 1955, 1949, 1938, 1921, 1908, 1941, 1943, 1932, 1948, 1924, 1989, 1974, 1977, 1994, 2033, 1948, 1907, 1948,
                     1880, 1915, 1941, 1921, 1949, 1938, 1958, 1956, 1937, 1931, 2032, 1996, 2008, 1937, 1937, 1935, 1962, 1941, 1938, 2029, 2013, 1999, 2021, 2029, 1899, 1886, 2013, 1871, 1853, 1901, 1860, 1907, 1880, 1910, 1943, 1881, 1893, 1873, 1870, 1908, 1917, 1908, 1904, 1895, 1854, 1889, 1900, 1857, 1934, 1873, 1936, 1920, 1900, 1903, 1925, 1910, 1886, 1924, 1891, 1905,
                     1883, 1854, 1918, 1860, 1912, 1879, 1913, 1898, 1905, 1874, 1893, 1870, 1910 };
int Cmotordata[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 1, 0, 1, 1, 1, 0, 14, 12, 14, 9, 11, 16, 9, 9, 9, 16, 28, 28, 32, 42, 39, 29, 29, 45, 36, 30, 60, 102, 109, 113, 124, 154, 153, 154, 151, 172, 183, 214, 243, 288, 302, 306, 320, 336, 337, 338, 356, 420, 438, 451, 465, 501, 499, 492, 509, 519, 528, 561, 567, 611, 632, 610, 616, 638, 641, 641, 667,
                     705, 721, 735, 724, 772, 756, 761, 748, 773, 774, 810, 817, 849, 840, 840, 861, 858, 876, 857, 883, 917, 917, 920, 932, 954, 936, 925, 918, 963, 951, 960, 995, 1011, 1011, 1008, 1011, 1052, 1022, 1033, 1014, 1059, 1059, 1092, 1053, 1092, 1080, 1056, 1062, 1097, 1111, 1096, 1094, 1170, 1131, 1137, 1134, 1158, 1174, 1137, 1185, 1234, 1198, 1203, 1192, 1223, 1194,
                     1207, 1204, 1241, 1222, 1252, 1229, 1291, 1232, 1241, 1226, 1246, 1244, 1225, 1230, 1298, 1295, 1271, 1270, 1306, 1300, 1280, 1265, 1357, 1283, 1278, 1307, 1369, 1297, 1337, 1299, 1357, 1326, 1326, 1316, 1375, 1341, 1373, 1366, 1351, 1366, 1326, 1314, 1404, 1364, 1373, 1366, 1417, 1431, 1381, 1349, 1468, 1383, 1367, 1352, 1460, 1411, 1420, 1400, 1471, 1435, 1415,
                     1429, 1455, 1424, 1432, 1406, 1506, 1447, 1444, 1416, 1511, 1438, 1442, 1476, 1578, 1498, 1444, 1440, 1521, 1539, 1448, 1448, 1539, 1492, 1518, 1464, 1604, 1565, 1503, 1468, 1539, 1479, 1492, 1481, 1582, 1549, 1495, 1525, 1618, 1543, 1515, 1546, 1631, 1597, 1532, 1569, 1712, 1577, 1537, 1557, 1621, 1596, 1532, 1546, 1721, 1572, 1566, 1562, 1645, 1602, 1592,
                     1580, 1708, 1587, 1587, 1599, 1639, 1566, 1576, 1540, 1699, 1664, 1561, 1593, 1731, 1589, 1613, 1563, 1695, 1608, 1628, 1597, 1721, 1737, 1613, 1613, 1772, 1665, 1670, 1656, 1758, 1645, 1649, 1603, 1772, 1702, 1688, 1678, 1782, 1685, 1718, 1650, 1863, 1793, 1687, 1717, 1804, 1782, 1695, 1704, 1789, 1769, 1674, 1715, 1867, 1795, 1675, 1702, 1761, 1673, 1676,
                     1667, 1765, 1708, 1721, 1667, 1792, 1728, 1681, 1674, 1792, 1770, 1745, 1698, 1816, 1797, 1715, 1776, 1938, 1796, 1742, 1745, 1911, 1832, 1800, 1772, 1930, 1752, 1721, 1714, 1920, 1805, 1730, 1711, 1864, 1862, 1700, 1762, 1897, 1805, 1753, 1761, 1951, 1790, 1749, 1773, 1947, 1781, 1712, 1782, 1901, 1799, 1732, 1724, 1856, 1772, 1759, 1751, 1923, 1846, 1765,
                     1765, 1944, 1822, 1791, 1776, 1945, 1854, 1830, 1800, 1921, 1860, 1776, 1748, 1954, 1874, 1858, 1773, 2035, 1852, 1775, 1826, 2072, 1934, 1859, 1897, 2003, 2054, 1860, 1887, 2214, 1993, 1970, 1874, 2041, 2043, 1894, 1839, 2080, 1905, 1822, 1907, 2124, 1935, 1857, 1883, 1957, 1940, 1860, 1870, 1865, 1877, 1876, 1846, 2092, 1928, 1825, 1833, 1979, 1914, 1920,
                     1837, 1988, 1900, 1867, 1825, 2049, 1964, 1834, 1857, 1979, 1893, 1815, 1874, 2002, 2023, 1803, 1877, 1894, 1989, 1840, 1846, 2001, 1958, 1861, 1867, 2066, 1952, 1853, 1806, 1894, 1880, 1769, 1767, 1893, 1840, 1780, 1787, 1857, 1814, 1780, 1722, 1859, 1920, 1800, 1840, 1853, 1823, 1776, 1771, 1843, 1871, 1819, 1769, 1900, 1876, 1792, 1809, 1908, 1944, 1859,
                     1920, 2073, 1985, 1913, 1917, 1940, 1897, 1883, 1807, 1910, 1910, 1873, 1826, 1917, 1893, 1802, 1802, 1886, 2008, 1859, 1814, 1930, 1905, 1850, 1833, 1909, 2019, 1850, 1807, 2012, 2010, 1938, 1856, 2051, 1890, 1848, 1842, 1958, 1950, 1874, 1915, 2029, 1947, 1827, 1867, 1949, 2022, 1957, 1941, 2161, 2040, 2018, 1894, 2005, 2118, 1986, 1951, 1936, 1927, 1946,
                     1978, 2025, 2019, 1888, 1904, 1964, 1914, 1822, 1834, 1945, 1924, 1873, 1853, 1995, 1975, 1830, 1894, 1958, 1958, 1848, 1786, 1907, 1959, 1952, 1964, 2020, 1927, 1901, 1903, 1986, 1931, 1921, 1985, 1972, 1993, 2028, 1859, 1927, 1901, 1904, 1861, 1936, 1937, 1928, 1902, 1937, 1971, 1944, 1840, 1948, 1972, 1955, 1942, 1972, 2073, 2057, 1924, 1925, 2036, 1893,
                     1836, 2008, 2060, 1947, 1957, 2156, 1976, 1905, 1914, 2022, 1985, 1947, 1920, 2058, 1968, 1893, 1929, 2042, 2052, 1975, 1867, 2063, 1962, 2011, 1948, 2070, 1957, 1911, 1843, 1944, 1945, 1902, 1878, 1964, 1864, 1930, 1870, 1942, 1958, 1941, 1898, 1898, 1923, 1948, 1921, 1957, 1934, 1952, 1924, 1942, 1901, 1950, 1894, 2016, 2062, 1975, 1893, 1921, 1978, 1935,
                     1857, 1955, 1921, 1866, 1841, 1890, 1876, 1821, 1855, 1961, 1895, 1877, 1852, 1873, 1857, 1915, 1820, 1850, 1897, 1856, 1833, 1921, 1915, 1823, 1807, 1904, 1830, 1817, 1790, 1911, 1864, 1883, 1843, 1915, 1989, 1917, 1863, 1921, 1951, 1958, 1971, 1958, 1983, 1901, 1934, 1934, 1987, 2011, 1979, 2023, 2059, 2026, 1890, 2052, 1931, 1917, 1923, 2126, 2036, 1965,
                     1899, 1971, 1913, 1870, 1835, 1911, 1962, 2005, 1971, 2039, 2050, 1986, 1857, 1993, 1958, 2041, 2025, 1969, 2004, 2012, 1931, 2101, 1939, 2006, 2063, 2035, 2146, 1971, 1972, 2018, 2028, 1917, 1835, 1923, 1988, 1884, 1924, 1947, 1894, 1968, 1952, 1931, 1909, 1914, 1883, 1901, 1933, 2001, 1952, 1992, 2019, 1938, 1952, 1921, 2009, 1999, 1982, 1985, 1949, 1907,
                     1968, 1911, 2006, 1935, 1944, 1921, 1924, 1981, 1930, 1928, 2046, 1877, 1811, 1888, 1912, 1866, 1887, 1918, 1929, 1913, 1922, 1923, 1915, 1918, 1918, 1937, 1981, 1948, 1959, 1978, 1972, 1981, 1920, 1994, 1995, 1987, 1890, 1929, 1985, 1978, 2042, 2070, 2006, 1999, 1948, 1961, 2046, 1971, 1984, 2097, 1942, 1937, 1887, 2011, 1999, 2016, 1979, 2008, 1992, 2034,
                     2003, 1988, 2052, 2025, 1931, 2030, 1952, 1900, 1878, 1930, 2038, 1954, 1941, 2003, 2013, 1992, 1920, 2005, 1957, 1960, 1911, 1931, 1954, 1927, 1935, 1971, 2023, 1931, 1900, 1962, 1952, 1979, 1941, 1957, 1985, 1944, 1961, 2029, 1998, 1995, 1946, 1955, 1949, 1938, 1921, 1908, 1941, 1943, 1932, 1948, 1924, 1989, 1974, 1977, 1994, 2033, 1948, 1907, 1948, 1880,
                     1915, 1941, 1921, 1949, 1938, 1958, 1956, 1937, 1931, 2032, 1996, 2008, 1937, 1937, 1935, 1962, 1941, 1938, 2029, 2013, 1999, 2021, 2029, 1899, 1886, 2013, 1871, 1853, 1901, 1860, 1907, 1880, 1910, 1943, 1881, 1893, 1873, 1870, 1908, 1917, 1908, 1904, 1895, 1854, 1889, 1900, 1857, 1934, 1873, 1936, 1920, 1900, 1903, 1925, 1910, 1886, 1924, 1891, 1905, 1883,
                     1854, 1918, 1860, 1912, 1879, 1913, 1898, 1905, 1874, 1893, 1870, 1910 };
//how much rpm the robot aims for
int AneedRPM = 0;
int BneedRPM = 0;
int CneedRPM = 0;
//kiwidrive values
double dirA = 0.00;
double dirB = 0.00;
double dirC = 0.00;
double spdA = 0.00;
double spdB = 0.00;
double spdC = 0.00;
double dirrad = 0.00;
double pi = 3.1415926535897;
#define m1enA 3    // GPA3  PWM1
#define m1enB 2    // GPA2
#define m1pwm1 0   // GPA0
#define m1pwm2 1   // GPA1
#define m1encA 12  // GPB4
#define m1encB 13  // GPB5
// motor two/B  left
#define m2enA 7    // GPA7  PWM2
#define m2enB 6    // GPA6
#define m2pwm1 4   // GPA4
#define m2pwm2 5   // GPA5
#define m2encA 14  // GPB6
#define m2encB 15  // GPB7
// motor three/C    right
#define m3enA 11   // GPB3  PWM3
#define m3enB 10   // GPB2
#define m3pwm1 8   // GPB0
#define m3pwm2 9   // GPB1
#define m3encA 24  // teensy port 24
#define m3encB 9   // teensy port 9
//encoder values
double Arpm = 0.00;
volatile long Aencount = 0;
unsigned long ALtime = 0;
unsigned long ACtime = 0;
unsigned long APtime = 0;
double Brpm = 0.00;
volatile long Bencount = 0;
unsigned long BLtime = 0;
unsigned long BCtime = 0;
unsigned long BPtime = 0;
double Crpm = 0.00;
volatile long Cencount = 0;
unsigned long CLtime = 0;
unsigned long CCtime = 0;
unsigned long CPtime = 0;
//softPWM values
volatile int PWMval1 = 0;  // PWM m1enA value 0-100
volatile int PWMval2 = 0;  // PWM m2enA value 0-100
volatile int PWMval3 = 0;  // PWM m3enA value 0-100

//settings
#define dip1 2  //settings dip switch port 1
#define dip2 3  //settings dip switch port 2
#define dip3 4  //settings dip switch port 3
#define dip4 5  //settings dip switch port 4
#define buz 8   //buzzer

//NOT USED CONNECT TO PULLUP
#define P1 6    //pin 6 on Teensy
#define P2 7    //pin 7 on Teensy
#define P3 10   //pin 10 on Teensy
#define P4 11   //pin 11 on Teensy
#define P5 12   //pin 12 on Teensy
#define P6 13   //pin 13 on Teensy
#define P7 14   //pin 14 on Teensy
#define P8 15   //pin 15 on Teensy
#define P9 16   //pin 16 on Teensy
#define P10 17  //pin 17 on Teensy
#define P11 20  //pin 20 on Teensy
#define P12 21  //pin 21 on Teensy
#define P13 22  //pin 22 on Teensy
#define P14 23  //pin 23 on Teensy
#define P15 29  //pin 29 on Teensy
#define P16 30  //pin 30 on Teensy
#define P17 31  //pin 31 on Teensy
#define P18 32  //pin 32 on Teensy
#define P19 33  //pin 33 on Teensy
#define P20 34  //pin 34 on Teensy
#define P21 35  //pin 35 on Teensy
#define P22 36  //pin 36 on Teensy
#define P23 37  //pin 37 on Teensy
#define P24 38  //pin 38 on Teensy
#define P25 39  //pin 39 on Teensy
#define P26 40  //pin 40 on Teensy
#define P27 41  //pin 41 on Teensy
//extra pins
// #define EP1 25 //pin 41 on Teensy used for IR seeker
#define EP2 26  //pin 41 on Teensy
#define EP3 27  //pin 41 on Teensy
#define EP4 28  //pin 41 on Teensy

volatile long IRcount1 = 0;
volatile long IRcount2 = 0;
volatile long IRcount3 = 0;
volatile long IRcount4 = 0;
volatile long IRcount5 = 0;
volatile long IRcount6 = 0;
volatile long IRcount7 = 0;
volatile long IRcount8 = 0;
volatile long IRcount9 = 0;
volatile long IRcount10 = 0;
volatile long IRcount11 = 0;
volatile long IRcount12 = 0;
volatile long IRcount13 = 0;
volatile long IRcount14 = 0;
volatile long IRcount15 = 0;
volatile long IRcount16 = 0;
volatile long IRcountBALL = 0;
int ballpos = 0;  //location of ball in degrees

int errorbuz = 0;  //if there is an error someware it goes to 1 and the buzzer starts

int ballinpos = 0;                                //is ball in our posesion. 0=no 1=yes
int colsensdata[6] = { 99, 99, 99, 99, 99, 99 };  //data colorsensors

int dip1val = 0;  //value of dip, 0=LOW, 1=HIGH
int dip2val = 0;
int dip3val = 0;
int dip4val = 0;
int settingval = 1;

Adafruit_MCP23X17 mcp1;  // Instance for the first MCP23017 at address 0x20
Adafruit_MCP23X17 mcp2;  // Instance for the second MCP23017 at address 0x22

Adafruit_TCS34725 tcs = Adafruit_TCS34725();  // Initialise color sensorwith default values (int time = 2.4ms, gain = 1x)

String tlocd = "";  //temp data for goal location
String locd = "";   //goal location in deg
int gloc = 0;       //goal location in deg int
bool readloc = false;
unsigned long datatime = 0;

LIS3MDL mag;
LSM6 imu;
int front = 0;
//enter calibration values
LIS3MDL::vector<int16_t> m_min = { +942, +3436, -3323 };
LIS3MDL::vector<int16_t> m_max = { +1053, +3559, -3142 };

void setup() {
  Serial.begin(9600);    //serial debug
  Serial1.begin(19200);  //connection to openMV

  //connect unconected pins to GND
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);
  pinMode(P4, INPUT_PULLUP);
  pinMode(P5, INPUT_PULLUP);
  pinMode(P6, INPUT_PULLUP);
  pinMode(P7, INPUT_PULLUP);
  pinMode(P8, INPUT_PULLUP);
  pinMode(P9, INPUT_PULLUP);
  pinMode(P10, INPUT_PULLUP);
  pinMode(P11, INPUT_PULLUP);
  pinMode(P12, INPUT_PULLUP);
  pinMode(P13, INPUT_PULLUP);
  pinMode(P14, INPUT_PULLUP);
  pinMode(P15, INPUT_PULLUP);
  pinMode(P16, INPUT_PULLUP);
  pinMode(P17, INPUT_PULLUP);
  pinMode(P18, INPUT_PULLUP);
  pinMode(P19, INPUT_PULLUP);
  pinMode(P20, INPUT_PULLUP);
  pinMode(P21, INPUT_PULLUP);
  pinMode(P22, INPUT_PULLUP);
  pinMode(P23, INPUT_PULLUP);
  pinMode(P24, INPUT_PULLUP);
  pinMode(P25, INPUT_PULLUP);
  pinMode(P26, INPUT_PULLUP);
  pinMode(P27, INPUT_PULLUP);
  //connect unconected extrapins to GND
  pinMode(EP2, INPUT_PULLUP);
  pinMode(EP3, INPUT_PULLUP);
  pinMode(EP4, INPUT_PULLUP);

  // Initialize first MCP23017 with I2C address 0x20
  if (!mcp1.begin_I2C(mcp1ADDR)) {
    Serial.println("(IR_sensors)Error initializing MCP23017 at 0x20.");
  }

  // Initialize second MCP23017 with I2C address 0x22
  if (!mcp2.begin_I2C(mcp2ADDR)) {
    Serial.println("(Motors)Error initializing MCP23017 at 0x22.");
  }
  //magnetometer
  if (!mag.init()) {
    Serial.println("Error initializing LIS3MDL magnetometer.");
  }
  //IMU
  if (!imu.init()) {
    Serial.println("Error initializing LSM6 IMU.");
  }
  imu.enableDefault();
  //get start heading to use as refreance point
  mag.read();
  imu.read();
  float heading = computeHeading();
  front = heading;
  Serial.println(heading);

  // Configure pins for the IR seekers
  mcp1.pinMode(ir1, INPUT);
  mcp1.pinMode(ir2, INPUT);
  mcp1.pinMode(ir3, INPUT);
  mcp1.pinMode(ir4, INPUT);
  mcp1.pinMode(ir5, INPUT);
  mcp1.pinMode(ir6, INPUT);
  mcp1.pinMode(ir7, INPUT);
  mcp1.pinMode(ir8, INPUT);
  mcp1.pinMode(ir9, INPUT);
  mcp1.pinMode(ir10, INPUT);
  mcp1.pinMode(ir11, INPUT);
  mcp1.pinMode(ir12, INPUT);
  mcp1.pinMode(ir13, INPUT);
  mcp1.pinMode(ir14, INPUT);
  mcp1.pinMode(ir15, INPUT);
  mcp1.pinMode(ir16, INPUT);
  pinMode(irBALL, INPUT);

  // Configure pins for the motor
  mcp2.pinMode(m1enA, OUTPUT);
  mcp2.pinMode(m1enB, OUTPUT);
  mcp2.pinMode(m2enA, OUTPUT);
  mcp2.pinMode(m2enB, OUTPUT);
  mcp2.pinMode(m3enA, OUTPUT);
  mcp2.pinMode(m3enB, OUTPUT);
  mcp2.pinMode(m1pwm1, OUTPUT);
  mcp2.pinMode(m1pwm2, OUTPUT);
  mcp2.pinMode(m2pwm1, OUTPUT);
  mcp2.pinMode(m2pwm2, OUTPUT);
  mcp2.pinMode(m3pwm1, OUTPUT);
  mcp2.pinMode(m3pwm2, OUTPUT);

  //set encoder pins
  mcp2.pinMode(m1encA, INPUT);
  mcp2.pinMode(m1encB, INPUT);
  mcp2.pinMode(m2encA, INPUT);
  mcp2.pinMode(m2encB, INPUT);
  pinMode(m3encA, INPUT);
  pinMode(m3encB, INPUT);

  //IR seeker interupts
  attachInterrupt(digitalPinToInterrupt(ir1), IRtrigger1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir2), IRtrigger2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir3), IRtrigger3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir4), IRtrigger4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir5), IRtrigger5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir6), IRtrigger6, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir7), IRtrigger7, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir8), IRtrigger8, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir9), IRtrigger9, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir10), IRtrigger10, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir11), IRtrigger11, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir12), IRtrigger12, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir13), IRtrigger13, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir14), IRtrigger14, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir15), IRtrigger15, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir16), IRtrigger16, CHANGE);
  attachInterrupt(digitalPinToInterrupt(irBALL), IRtrigger16, CHANGE);

  //encoder interupst
  attachInterrupt(digitalPinToInterrupt(m1encA), AencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m1encB), AencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m2encA), BencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m2encB), BencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m3encA), CencoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m3encB), CencoderISR, CHANGE);

  //PWM interupst
  Timer3.initialize(800);  // 800 microseconds or 1.25kHz
  Timer3.attachInterrupt(updatePWM1);
  Timer3.attachInterrupt(updatePWM2);
  Timer3.attachInterrupt(updatePWM3);

  pinMode(buz, OUTPUT);
  Serial.println("SETUP COMPLETE GOING TO LOOP");
  tone(buz, 1000);
}
void updatePWM1() {
  static int counter1 = 0;
  if (counter1 < PWMval1) {
    mcp2.digitalWrite(m1enA, HIGH);
  } else {
    mcp2.digitalWrite(m1enA, LOW);
  }
  counter1++;
  if (counter1 >= 100) {
    counter1 = 0;
  }
}
void updatePWM2() {
  static int counter2 = 0;
  if (counter2 < PWMval2) {
    mcp2.digitalWrite(m2enA, HIGH);
  } else {
    mcp2.digitalWrite(m2enA, LOW);
  }
  counter2++;
  if (counter2 >= 100) {
    counter2 = 0;
  }
}
void updatePWM3() {
  static int counter3 = 0;
  if (counter3 < PWMval3) {
    mcp2.digitalWrite(m3enA, HIGH);
  } else {
    mcp2.digitalWrite(m3enA, LOW);
  }
  counter3++;
  if (counter3 >= 100) {
    counter3 = 0;
  }
}
void mcpsoftpwm(int pin, int vall) {
  //M1enA = 3   = GPA3
  //M2enA = 7   = GPA7
  //M3enA = 11  = GPB3
  Serial.print("softPWM pin: ");
  Serial.print(pin);
  Serial.print(", value: ");
  Serial.println(vall);
  if (pin = 3) {
    PWMval1 = vall;
    Serial.print("Motor 1 enA PWM set");
  }
  if (pin = 7) {
    PWMval2 = vall;
    Serial.print("Motor 2 enA PWM set");
  }
  if (pin = 11) {
    PWMval3 = vall;
    Serial.print("Motor 3 enA PWM set");
  }
}

void AencoderISR() {
  Aencount++;
}
void BencoderISR() {
  Bencount++;
}
void CencoderISR() {
  Cencount++;
}

void IRtrigger1() {
  IRcount1++;
}
void IRtrigger2() {
  IRcount2++;
}
void IRtrigger3() {
  IRcount3++;
}
void IRtrigger4() {
  IRcount4++;
}
void IRtrigger5() {
  IRcount5++;
}
void IRtrigger6() {
  IRcount6++;
}
void IRtrigger7() {
  IRcount7++;
}
void IRtrigger8() {
  IRcount8++;
}
void IRtrigger9() {
  IRcount9++;
}
void IRtrigger10() {
  IRcount10++;
}
void IRtrigger11() {
  IRcount11++;
}
void IRtrigger12() {
  IRcount12++;
}
void IRtrigger13() {
  IRcount13++;
}
void IRtrigger14() {
  IRcount14++;
}
void IRtrigger15() {
  IRcount15++;
}
void IRtrigger16() {
  IRcount16++;
}
void IRtriggerBALL() {
  IRcountBALL++;
}

void pcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void Areadenc() {
  ACtime = micros();
  APtime = ACtime - ALtime;
  ALtime = ACtime;
  Arpm = (Aencount / 211.2) * (60000000.0 / APtime);
  Serial.print("Motor A RPM: ");
  Serial.print(Arpm);
  Serial.print("    Sample period:");
  Serial.print(APtime);
  Serial.print("ms, encoder count:");
  Serial.println(Aencount);
  Aencount = 0;
}
void Breadenc() {
  BCtime = micros();
  BPtime = BCtime - BLtime;
  BLtime = BCtime;
  Brpm = (Bencount / 211.2) * (60000000.0 / BPtime);
  Serial.print("Motor B RPM: ");
  Serial.print(Brpm);
  Serial.print("    Sample period: ");
  Serial.print(BPtime);
  Serial.print(" ms, encoder count: ");
  Serial.println(Bencount);
  Bencount = 0;
}
void Creadenc() {
  CCtime = micros();
  CPtime = CCtime - CLtime;
  CLtime = CCtime;
  Crpm = (Cencount / 211.2) * (60000000.0 / CPtime);
  Serial.print("Motor C RPM: ");
  Serial.print(Crpm);
  Serial.print("    Sample period: ");
  Serial.print(CPtime);
  Serial.print(" ms, encoder count: ");
  Serial.println(Cencount);
  Cencount = 0;
}
void Aresetenc() {
  ACtime = micros();
  ALtime = ACtime;
  Aencount = 0;
}
void Bresetenc() {
  BCtime = micros();
  BLtime = BCtime;
  Bencount = 0;
}
void Cresetenc() {
  CCtime = micros();
  CLtime = CCtime;
  Cencount = 0;
}

void Amove(double Rsped) {
  double sped = nearest(Rsped, Amotordata, ArrayElementCount(Amotordata));
  spdA = abs(sped) * 0.1;
  mcpsoftpwm(m1enA, spdA);
  mcp2.digitalWrite(m1enB, LOW);
  if (sped < 0) {
    Serial.print("Motor A back ");
    mcp2.digitalWrite(m1pwm1, LOW);
    mcp2.digitalWrite(m1pwm2, HIGH);
  } else {
    Serial.print("Motor A forward ");
    mcp2.digitalWrite(m1pwm1, HIGH);
    mcp2.digitalWrite(m1pwm2, LOW);
  }
  Serial.println(spdA);
}
void Bmove(double Rsped) {
  double sped = nearest(Rsped, Bmotordata, ArrayElementCount(Bmotordata));
  spdB = abs(sped) * 0.1;
  mcpsoftpwm(m2enA, spdB);
  mcp2.digitalWrite(m2enB, LOW);
  if (sped < 0) {
    Serial.print("Motor B back ");
    mcp2.digitalWrite(m2pwm1, LOW);
    mcp2.digitalWrite(m2pwm2, HIGH);
  } else {
    Serial.print("Motor B forward ");
    mcp2.digitalWrite(m2pwm1, HIGH);
    mcp2.digitalWrite(m2pwm2, LOW);
  }
  Serial.println(spdB);
}
void Cmove(double Rsped) {
  double sped = nearest(Rsped, Cmotordata, ArrayElementCount(Cmotordata));
  spdC = abs(sped) * 0.1;
  mcpsoftpwm(m3enA, spdC);
  mcp2.digitalWrite(m3enB, LOW);
  if (sped < 0) {
    Serial.print("Motor C back ");
    mcp2.digitalWrite(m3pwm1, LOW);
    mcp2.digitalWrite(m3pwm2, HIGH);
  } else {
    Serial.print("Motor C forward ");
    mcp2.digitalWrite(m3pwm1, HIGH);
    mcp2.digitalWrite(m3pwm2, LOW);
  }
  Serial.println(spdC);
}

void moveohmi(int speed, int direction) {
  Amove(0);
  Bmove(0);
  Cmove(0);

  double dirrad = (direction * 71.0000) / 4068.0000;
  Serial.println(dirrad);
  //vector ontbinden in x en y
  double y = sin(dirrad);
  double x = cos(dirrad);
  Serial.println((String) "x:" + x + " y:" + y);
  double spdeA = y * speed;                             //speed motor A = Y vector
  double spdeB = (-0.500 * x - 0.8660054 * y) * speed;  //speed motor B = -1/2 X - sqrt(3)/2 Y
  double spdeC = (-0.500 * x + 0.8660054 * y) * speed;  //speed motor C = -1/2 X + sqrt(3)/2 Y
  Amove(spdeA);
  Bmove(spdeB);
  Cmove(spdeC);
  Serial.println();
  Serial.println();
}
void rotate(int speed) {
  Amove(speed);
  Bmove(speed);
  Cmove(speed);
}
void compasrotate(int speed, int direction, int accuracy, int curheading) {
  //inacurate compas data
  //0deg is start heading offset(deg)
  int headmin = direction - accuracy;
  if (headmin < 0) {
    headmin = 360 - headmin;
  }
  int headmax = direction + accuracy;
  if (headmax > 360) {
    headmax = headmax - 360;
  }
  if (!(curheading >= headmin) && !(curheading <= headmax)) {
    if ((direction - curheading) > 180) {
      Amove(-speed);
      Bmove(-speed);
      Cmove(-speed);
    } else {
      Amove(speed);
      Bmove(speed);
      Cmove(speed);
    }
  }
}

void loop() {
  /*
  1. it proceses/collects the sensor data
  2. It prints the data for debugging
  3. It do stuff with the data
  */
  /*
  1. collect data
  2. do stuff with data --> 3
  3. check if we are on any white lines:
        Yes: go oppiside direction for 250ms --> 1
        No: --> 4 
  4. do we have the ball
        Yes: go towards goal --> 1
        No: --> 5
  5. Go towards the ball --> 1
  */
  Wire.begin();
  //IR sensors data collection done in background, finding highest value and see if we have ball in posesion
  volatile long IRcounts[] = { IRcount1, IRcount2, IRcount3, IRcount4, IRcount5, IRcount6, IRcount7, IRcount8, IRcount9, IRcount10, IRcount11, IRcount12, IRcount13, IRcount14, IRcount15, IRcount16 };
  long maxCount = IRcounts[0];
  int highessensor = 1;
  for (int i = 0; i < 15; ++i) {
    if (IRcounts[i] > maxCount) {
      maxCount = IRcounts[i];
      highessensor = i + 1;
      ballpos = (360 - (22.5 * i));
    }
  }
  if (IRcountBALL > minpulsbal) {
    ballinpos = 1;
  } else {
    ballinpos = 0;
  }
  //Read color sensors
  for (uint8_t t = 0; t < 6; t++) {
    pcaselect(t);
    for (uint8_t addr = 0; addr <= 127; addr++) {
      if (addr == PCAADDR) continue;
      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        if (tcs.begin()) {
          uint16_t r, g, b, c, colorTemp, lux;
          tcs.getRawData(&r, &g, &b, &c);
          colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
          lux = tcs.calculateLux(r, g, b);
          if ((colorTemp) == 5201) {
            colsensdata[t] = 0;
          } else if ((g) >= (2 * (r)) && (g) >= 12) {
            colsensdata[t] = 1;
          } else if ((colorTemp) >= 6750) {
            colsensdata[t] = 2;
          } else if ((colorTemp) < 6750) {
            colsensdata[t] = 3;
          } else {
            Serial.println(colorTemp);
            colsensdata[t] = 98;
          }
        } else {
          Serial.println("No TCS34725 found ... check your connections");
          colsensdata[t] = 97;
        }
      }
    }
  }
  //read camera
  if (Serial1.available()) {
    datatime = millis();

    byte byteRead = Serial1.read();

    if (byteRead == 's') {
      tlocd = "";
      readloc = true;
    } else if (byteRead == 'e') {
      readloc = false;
      locd = tlocd;
    } else if (readloc == true) {
      tlocd += (char)byteRead;
    }
  } else {
    if (millis() - datatime > 5000) {
      locd = "999";
    }
  }
  int gloc = locd.toInt();
  //read and calculate compas
  mag.read();
  imu.read();
  float heading = computeHeading();
  int offset = heading - front;
  if (offset < 0) {
    offset = (offset + 360);
  }
  //read dip settings
  dip1val = digitalRead(dip1);
  dip2val = digitalRead(dip2);
  dip3val = digitalRead(dip3);
  dip4val = digitalRead(dip4);
  //printing sensor data
  //IR
  Serial.println("IR data: ");
  Serial.print("ir 1 changes: ");
  Serial.print(IRcount1);
  Serial.print(", ir 2 changes: ");
  Serial.print(IRcount2);
  Serial.print(", ir 3 changes: ");
  Serial.print(IRcount3);
  Serial.print(", ir 4 changes: ");
  Serial.print(IRcount4);
  Serial.print(", ir 5 changes: ");
  Serial.print(IRcount5);
  Serial.print(", ir 6 changes: ");
  Serial.print(IRcount6);
  Serial.print(", ir 7 changes: ");
  Serial.print(IRcount7);
  Serial.print(", ir 8 changes: ");
  Serial.print(IRcount8);
  Serial.print(", ir 9 changes: ");
  Serial.print(IRcount9);
  Serial.print(", ir 10 changes: ");
  Serial.print(IRcount10);
  Serial.print(", ir 11 changes: ");
  Serial.print(IRcount11);
  Serial.print(", ir 12 changes: ");
  Serial.print(IRcount12);
  Serial.print(", ir 13 changes: ");
  Serial.print(IRcount13);
  Serial.print(", ir 14 changes: ");
  Serial.print(IRcount14);
  Serial.print(", ir 15 changes: ");
  Serial.print(IRcount15);
  Serial.print(", ir 16 changes: ");
  Serial.println(IRcount16);
  Serial.print(", ball in posesion ir changes: ");
  Serial.println(IRcountBALL);
  Serial.print("Ball is at sensor: ");
  Serial.print(highessensor);
  Serial.print(", with value of ");
  Serial.print(maxCount);
  Serial.print(", withs it also at");
  Serial.print(ballpos);
  Serial.print(" degrees");
  if (ballinpos == 1) {
    Serial.print("Ball is in our posesion with: ");
    Serial.print(IRcountBALL);
    Serial.println(" pulses.");
  } else {
    Serial.println("ball is not in our posesion");
  }
  //color
  Serial.print("sensor data = ");  // 0=air, 1=green, 2=black, 3=white, 90=error
  for (int i = 0; i < 6; i++) {
    Serial.print(colsensdata[i]);
    Serial.print(", ");
  }
  Serial.println();
  //camera
  Serial.print("location of the goal is: ");
  if (gloc == 999) {
    Serial.println("unknown, there is no working connection with the camera");
  } else {
    Serial.println(gloc);
  }
  //compas
  Serial.print("heading: ");
  Serial.print(heading);
  Serial.print(", goal location: ");
  Serial.print(front);
  Serial.print(", offset: ");
  //dip
  if ((dip1val = 0) && (dip1val = 1)) {
    settingval = 1;
  } else if ((dip1val = 1) && (dip1val = 1)) {
    settingval = 2;
  } else if ((dip1val = 0) && (dip1val = 0)) {
    settingval = 3;
  } else if ((dip1val = 1) && (dip1val = 0)) {
    settingval = 4;
  }


  /*
  dip 1-4 settings: 
  dip 1 = rotation    1=enables 0 = disables
  dip 2 = buzzer      err/debug (buzz only if err = 1 -debug buzz = 0)
  dip 3 = on/off      1=on 0 = off
  dip 4 = camera      1=enables 0 = disables
  settings:
    1.  rotation OFF
        camera ON
    2.  rotation ON
        camera ON
    3.  rotation OFF
        camera OFF
    4.  rotation ON
        camera OFF
  /*dip3val



  
  /*
  data we have:
    rotation since start: offset(deg)
    if we have an ball in posesion ballinpos = 1, else ballinpos = 0
    location of the ball on the field: ballpos(deg)
    colorsensordata list: colsensdata[6]. 0=air, 1=green, 2=black, 3=white, 90=error
    goal location: gloc(deg)
  */
  //select with version of the code using dip switches

  //do stuf with data version 1: rotation disables and camera enabled
  if (dip3val = 1) {
    if (settingval = 1) {
      //check if we arent on any white lines
      for (int i = 0; i < 6; i++) {
        if (colsensdata[i] = 3) {
          Serial.println((String) "detected white collor on sensor:" + i + "going back " + (360 - (i * 60)) + "degrees");
          moveohmi(sp, (i * 60));
          delay(250);
          return;  //restart loop
        }
      }
      //if we have the bal go towards the goal
      if (ballinpos = 1) {
        moveohmi(sp, 0);
      } else {  //go towards ball
        moveohmi(sp, ballpos);
      }
    }

    //do stuf with data version 2: rotation enabled and camera enabled    N
    if (settingval = 2) {
      //check if we arent on any white lines
      for (int i = 0; i < 6; i++) {
        if (colsensdata[i] = 3) {
          Serial.println((String) "detected white collor on sensor:" + i + "going back " + (360 - (i * 60)) + "degrees");
          moveohmi(sp, (i * 60));
          delay(250);
          return;  //restart loop
        }
        if (ballinpos = 1) {
          moveohmi(sp, gloc);
        } else {  //go towards ball
          moveohmi(sp, ballpos);
        }
      }
    }

    //do stuf with data version 3: rotation disabled and camera disabled (use compas to detect goal)
    if (settingval = 3) {
      //check if we arent on any white lines
      for (int i = 0; i < 6; i++) {
        if (colsensdata[i] = 3) {
          Serial.println((String) "detected white collor on sensor:" + i + "going back " + (360 - (i * 60)) + "degrees");
          moveohmi(sp, (i * 60));
          delay(250);
          return;  //restart loop
        }
      }
    }

    //do stuf with data version 4: rotation enabled and camera disabled (use compas to detect goal)
    if (settingval = 4) {
      //check if we arent on any white lines
      for (int i = 0; i < 6; i++) {
        if (colsensdata[i] = 3) {
          Serial.println((String) "detected white collor on sensor:" + i + "going back " + (360 - (i * 60)) + "degrees");
          moveohmi(sp, (i * 60));
          delay(250);
          return;  //restart loop
        }
      }
    }
  } else {
    Serial.println("skipping loop robot is off");
  }

  if (errorbuz = 1) {
    tone(buz, 2000);
  }


  Serial.println();
  Serial.println();
  Serial.println();
}


template<typename T> float computeHeading(LIS3MDL::vector<T> from) {
  //from https://github.com/pololu/lis3mdl-arduino/tree/master/examples/HeadingWithLSM6
  LIS3MDL::vector<int32_t> temp_m = { mag.m.x, mag.m.y, mag.m.z };

  // copy acceleration readings from LSM6::vector into an LIS3MDL::vector
  LIS3MDL::vector<int16_t> a = { imu.a.x, imu.a.y, imu.a.z };

  // subtract offset (average of min and max) from magnetometer readings
  temp_m.x -= ((int32_t)m_min.x + m_max.x) / 2;
  temp_m.y -= ((int32_t)m_min.y + m_max.y) / 2;
  temp_m.z -= ((int32_t)m_min.z + m_max.z) / 2;

  // compute E and N
  LIS3MDL::vector<float> E;
  LIS3MDL::vector<float> N;
  LIS3MDL::vector_cross(&temp_m, &a, &E);
  LIS3MDL::vector_normalize(&E);
  LIS3MDL::vector_cross(&a, &E, &N);
  LIS3MDL::vector_normalize(&N);

  // compute heading
  float heading = atan2(LIS3MDL::vector_dot(&E, &from), LIS3MDL::vector_dot(&N, &from)) * 180 / PI;
  if (heading < 0) heading += 360;
  return heading;
}

/*
Returns the angular difference in the horizontal plane between a
default vector (the +X axis) and north, in degrees.
*/
float computeHeading() {
  //from https://github.com/pololu/lis3mdl-arduino/tree/master/examples/HeadingWithLSM6
  return computeHeading((LIS3MDL::vector<int>){ 1, 0, 0 });
}
int nearest(int x, int myArray[], int elements) {
  //https://forum.arduino.cc/t/search-for-nearest-number-in-an-array-help/245843/5
  int idx = 0;  // by default near first element

  int distance = abs(myArray[idx] - x);
  for (int i = 1; i < elements; i++) {
    int d = abs(myArray[i] - x);
    if (d < distance) {
      idx = i;
      distance = d;
    }
  }
  return idx;
}
