TARGETS := all clean
SUBDIRS := vmmon-only vmnet-only

$(TARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) VM_UNAME=$(KERNELRELEASE) -C $@ $(MAKECMDGOALS)

.PHONY: all clean $(SUBDIRS)
