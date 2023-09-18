DIRS=Q1 Q2

.PHONY: $(DIRS)

all: $(DIRS)

$(DIRS):
	make -C $@

clean:
	@for d in $(DIRS); do \
		make -C $$d clean; \
	done
