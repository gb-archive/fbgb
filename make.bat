@set CC=lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG

%CC% -c fb_sound.c 
%CC% -c fbgb.c

%CC% -Wl -o fbgb.gb fbgb.o fb_sound.o

del *.lst
del *.map
del *.sym
