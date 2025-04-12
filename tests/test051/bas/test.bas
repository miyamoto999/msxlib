6 r=rnd(-time)
10 screen 7
20 cls
30 for x=0 to 511
40 line (x,0)-(511-x,211),rnd(1)*14+1
50 next x
51 for y=0 to 211
52 line (0,211-y)-(511,y),rnd(1)*14+1
53 next y
60 copy (0,0)-(511,211) to "g.bin"

