# QtWanring
 去掉Qt加载png时候的警告
```
libpng warning: iCCP: known incorrect sRGB profile
libpng warning: iCCP: cHRM chunk does not match sRGB
```
# 原理
```
QImage image("xxx.png");
image.save("xxx.png");
```
