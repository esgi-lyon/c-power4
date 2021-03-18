CC:=clang
TARGET_EXEC ?= c-power4-$(shell uname -p)-$(shell uname)

BUILD_DIR ?= ./build

# Usage : make
SRC_DIRS := ./cli ./game ./lib
SKIP_EXEC ?= false

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
EXECUTE = chmod +x $@ && $@ $(1)
CFLAGS := -Wall -Wextra -Werror --std=c99

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(CC) $(OBJS) -o $@ $(LDFLAGS)
ifeq ($(SKIP_EXEC), false)
	@$(call EXECUTE, $(ARGS))
endif

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: debug

debug:
	@echo $(SRC_DIRS)
	@echo $(INC_DIRS)

-include $(DEPS)

MKDIR_P ?= mkdir -p
