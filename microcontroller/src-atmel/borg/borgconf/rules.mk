
OBJECTS += $(patsubst %.c,obj_avr/%.o,${SRC})
OBJECTS += $(patsubst %.S,obj_avr/%.o,${ASRC})

#./obj_avr/%.a: $(OBJECTS)
#	$(AR) qcv $@ $^
#	$(STRIP) --strip-unneeded $@

./obj_avr/%.o: %.S
	$(CC) -o $@ $(CPPFLAGS) $(ASFLAGS) -c $<

./obj_avr/%.o: %.c
	if [ ! -d obj_avr ]; then mkdir obj_avr ; fi
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c $<

clean-common:
	$(RM) $(TARGET) *.[odasE] *.d.new *~
	$(RM) -r ./obj_avr

clean: clean-common

all:
	make -C $(TOPDIR) all
	
objects_avr: $(OBJECTS)
	echo $(OBJECTS) > obj_avr/.objects
	

include $(TOPDIR)/depend.mk
