

# "make" and "make test" are the same thing: build the bigint library
#        and the regression test program

# "make clean" cleans up

# "make realclean" cleans even better

# "make depend" Creates the dependencies to help make know what needs
#       to be rebuilt. You only need to run this once after unpacking.

# "make tarfile" Does a "make realclean" then creates a compressed tar file.

# Change the following two lines to your first and last name.

FIRST_NAME=mangesh
LAST_NAME=sakordekar

# You can add more assembly files as you go.  Just edit the C code and
# put #ifdef around the function you want to change to assembly (look
# at bigint_adc() for an example), then create the new assembly (.S)
# file and add it to the ASMOBJS list.  Use .o instead of .S in the
# ASMOBJS list (see commented example below), and make will find the
# .S file. Do "make clean" to force a complete rebuild.



C_OBJECTS =   simon.o scorec.o
ASM_OBJECTS = buttons.o lightm2.o light.o readbutton.o Rp_IO.o

simon: $(C_OBJECTS) $(ASM_OBJECTS)
	gcc -g -o simon $(C_OBJECTS) $(ASM_OBJECTS)

.c.o:
	gcc -I. -g -c $<

.S.o:
	gcc -I. -g -c $< 

clean:
	rm -f *.o simon *~


tarfile: #realclean report.pdf
	rm -f $(LAST_NAME)_$(FIRST_NAME).tgz
	cp -rp . /tmp/$(LAST_NAME)_$(FIRST_NAME)

	cd /tmp; tar cfz $(LAST_NAME)_$(FIRST_NAME).tgz $(LAST_NAME)_$(FIRST_NAME)
	mv /tmp/$(LAST_NAME)_$(FIRST_NAME).tgz .
	rm -rf /tmp/$(LAST_NAME)_$(FIRST_NAME)
#	make depend

report.pdf:
	$(error report.pdf not found. Aborting.)

#clean:
#	rm -f *.o test core.* libbigint.a CSC314_program1.tgz

#realclean: clean
#	rm -f *~ .depend 

# make depend will create a file ".depend" with all the C dependencies
#depend:
#	rm -f .depend
#	$(CC) $(DEFINES) $(INCLUDES) $(DEPENDFLAGS) $(COBJS:.o=.c) > .depend

# if we have a .depend file, include it
ifeq (.depend,$(wildcard .depend))
include .depend
endif

#	rm /tmp/$(LAST_NAME)_$(FIRST_NAME)/regression_tests.dat
