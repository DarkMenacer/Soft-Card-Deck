cmake_minimum_required(VERSION 3.29.3)

project(SoftCardDeck)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(SFML REQUIRED)

add_executable(${PROJECT_NAME} "src/main.cpp"
	"src/constants/Card_Constants.cpp"
	"src/models/Card/Card.cpp"
	"src/models/Deck/Deck.cpp"
	"src/utils/UUID/UUID.cpp"
)

target_link_libraries(${PROJECT_NAME} sfml::sfml)
