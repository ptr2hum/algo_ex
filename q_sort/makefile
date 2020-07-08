#!/usr/bin/make -f
#This is a trivial one to learn how to write makefie
#so, many features written here can be redundent
#but helpful to learn makefile
#the first line of script file is usually hashbang for specifying interpreter.
#
#basic forms of this script are
#[variable]= [valus] 
#and
#[target]: [prerequisites]
###########Variables################################
SHELL=/bin/sh #makefiles have several convention
.SUFFIXES: #delete file extention
.SUFFIXES: .c .o .do #declare file extention rule.

VPATH=~/my_ex/algo_ex/q_sort/:../ #default is pwd
.RECIPEPREFIX=> # can replace recipe prefix with [tab]
# the first character of the variable is used as the prefix

#:= or :== are used for a simply expanded var, differed from recursive expanded var.
#the value of a simply expanded var is scanned once and for all
OBJS = quick_sort.o random.o qsort.o
DBOBJS = $(OBJS:.o=.do)
#quick_sort.do qsort.do random.do
DFLAG= -DDEBUG  -Wall
override DFLAG += -g #this can be worked
CFLAG= -w -O
EXECNAME ?= qsort #identical var
CC= gcc

############suffix rule############################
#suffix rule is old-fashioned and now replaced with pattern rule
#there is no prerequisites. and should have recipes
#.c is src, .o is target. this is doubel suffix rule
#.c.o:; $(CC) -c -o $@ $(CFLAGS) $< #used implicit rule; CFLAGS
#.c.do:; $(CC) -c -o $@ $(DFLAG) $<

#automatic variables
#$@ is name of target, $< is name of fist prerequisite,
#$? is newer prerequitse, $* is file name except extention
#$^ is the names of all the prerequisites with spaces between them.
###########pattern rule############################
#%.o:%.c; recipe.. #can have prerequisites, and no recipe
%.o : %.c
>$(CC) -c $(CFLAG) $(CPPFLAGS) $< -o $@
%.do : %.c
>$(CC) -c $(DFLAG) $(CPPFLAGS) $< -o $@

#% :: RCS/%,v ;$(CO) $(COFLAG) $<  #this will apply to any file
#terminal :: means that its prerequiste may not be an intermediate file
#=> see chained rulle
##########rules have following format######################
#target: prerequisites {;recipe}<-optional
#recipeprefix recipes...

define run-debug =
$(CC)  $(DFLAG) -o $(EXECNAME) $(DBOBJS)
endef
#execution file
.PHONY: exec debug #phony target
#phony target can be used when target name isn't a file name
exec: $(OBJS)
>$(CC) $(CFLAG) -o $(EXECNAME)  $(OBJS)
debug: $(DBOBJS)
#>$(CC)  $(DFLAG) -o $(EXECNAME) $(DBOBJS)
>$(run-debug) #comments in the recipe echoing
#canned recipe

FILESQS:= $(shell $(CC) -MM quick_sort.c) #shell fuction
# gcc -M will print dependency list of specified file for prerequisites
# -MM excludes system header files
FILESRD:= random.c random.h
FILESQS:= qsort.c qsort.h
#object module target
quick_sort.o: $(FILESQS)#can omit the recipes for .o files ,
#cuz make use Implict Rules or predefined pattern rules
random.o: $(FILESRD)
qsort.o: $(FILESQS)
#debugging obj module target
quick_sort.do: $(FILESQS:.o=.do) #substitute string
#functions for transforming text can be used
random.do: $(FILESRD)
qsort.do:  $(FILESQS)

.RECIPEPREFIX=
#recipeprefix variable can be modified several times

#etc...
cpp:
	$(CC) -E random.c
aasm:
	$(CC) -S random.c

.PHONY:clean #ls #if ls is in this list, the result would be different
clean:
	rm -f *.do *.o *.s *~ $(EXECNAME)
ls:*.c
	ls -l $? #$? is automatic variable
	touch ls

FOO = $PATH
value:
	echo echoing
	@echo $(F00) 
	@echo $(value FOO)
#make prints each line of the recipe before it is executed. it called echoing.
#when a line starts with @, the echoing of that line is suppressed.

