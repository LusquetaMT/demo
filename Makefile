CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/main.cpp \
      src/views/MainMenuView.cpp \
      src/views/ProductView.cpp \
      src/controllers/ProductController.cpp \
      src/models/Product.cpp \
      src/utils/TimeUtils.cpp \
	  src/utils/StringUtils.cpp \
	  src/services/ProductService.cpp \
	  src/repositories/ProductRepository.cpp

TARGET = main.exe

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del $(TARGET)