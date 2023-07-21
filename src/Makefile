CURR_DIR := .
BUILD_DIR := $(CURR_DIR)/build
MODEL_DIR := $(CURR_DIR)/model
VIEW_DIR := $(CURR_DIR)/view
CONTROLLER_DIR := $(CURR_DIR)/controller

RM := rm -f
MK := mkdir -p

EXEC := smartcalc
ARCHIVE := $(CURR_DIR)/$(EXEC)

all: tests install run

install:
	@$(MK) $(BUILD_DIR)
	@cmake $(CURR_DIR) -S $(VIEW_DIR) -B $(BUILD_DIR)
	@cd $(BUILD_DIR) ; $(MAKE) ; cd ..

uninstall:
	@$(RM) -r view/$(BUILD_DIR)

run:
	@$(BUILD_DIR)/smartcalc

dist: create_dirs cpy_files
	tar cvzf $(ARCHIVE).tgz $(ARCHIVE)
	mv $(ARCHIVE).tgz $(CURR_DIR)/..
	$(RM) -r $(ARCHIVE)

# dvi:
# 	makeinfo documentation.texi --html
# 	open ./manual/index.html

create_dirs:
	@$(RM) -r $(ARCHIVE)
	@$(MK) $(ARCHIVE)
	@$(MK) $(ARCHIVE)/src
	@$(MK) $(ARCHIVE)/src/model
	@$(MK) $(ARCHIVE)/src/view
	@$(MK) $(ARCHIVE)/src/controller
	@$(MK) $(ARCHIVE)/src/model/sources
	@$(MK) $(ARCHIVE)/src/model/includes
	@$(MK) $(ARCHIVE)/src/model/tests
	@$(MK) $(ARCHIVE)/src/model/CMakeModels
	@$(MK) $(ARCHIVE)/src/view/sources
	@$(MK) $(ARCHIVE)/src/view/includes
	@$(MK) $(ARCHIVE)/src/view/qcustomplot
	@$(MK) $(ARCHIVE)/src/controller/sources
	@$(MK) $(ARCHIVE)/src/controller/includes

cpy_files:
	cp Makefile $(ARCHIVE)/src
	# cp documentation.texi $(ARCHIVE)/src
	cp $(CURR_DIR)/model/sources/* $(ARCHIVE)/src/model/sources
	cp $(CURR_DIR)/model/includes/* $(ARCHIVE)/src/model/includes
	cp $(CURR_DIR)/model/tests/* $(ARCHIVE)/src/model/tests
	cp $(CURR_DIR)/model/CMakeModules/* $(ARCHIVE)/src/model/CMakeModules
	cp $(CURR_DIR)/model/Makefile $(ARCHIVE)/src/model
	cp $(CURR_DIR)/model/CMakeLists.txt $(ARCHIVE)/src/model
	cp $(CURR_DIR)/view/sources/* $(ARCHIVE)/src/view/sources
	cp $(CURR_DIR)/view/includes/* $(ARCHIVE)/src/view/includes
	cp $(CURR_DIR)/view/qcustomplot/* $(ARCHIVE)/src/view/qcustomplot
	cp $(CURR_DIR)/view/main.cc $(ARCHIVE)/src/view
	cp $(CURR_DIR)/view/CMakeLists.txt $(ARCHIVE)/src/view
	cp $(CURR_DIR)/controller/sources/* $(ARCHIVE)/src/controller/sources
	cp $(CURR_DIR)/controller/includes/* $(ARCHIVE)/src/controller/includes

tests:
	@cd $(MODEL_DIR) ; $(MAKE) test ; cd ./..

gcov_report:
	@cd $(MODEL_DIR) ; $(MAKE) gcov ; cd ./..

# gcov_report:
# 	@cd $(LOGIC_DIR) ; make gcov_report ; cd ./..

clean: uninstall
	@cd $(MODEL_DIR) ; $(MAKE) clean ; cd ./..
	@$(RM) -r ../*.tgz
	# @$(RM) -r manual/
