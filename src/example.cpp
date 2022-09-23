#include "Logger.hpp"



int main() {

	Logger log = Logger();

	log.info("Begin");
	log.info("1");
	log.info("2");
	log.info("3");
	log.info("4");

	std::this_thread::sleep_for(std::chrono::seconds(1));
	log.info("Done sleeping");

	log.info("Exit");
	std::cout << "Main is done executing" << std::endl;


	// The logger will throw an error if invalid inputs are detected.
	// Below, the "\\" is not allowed as a seperator
	try {
		Logger logger = Logger("secondaryLogger", "log.txt", "", "INFO", "\\", 1);
	}
	catch (const std::invalid_argument& error) {
		std::cout << error.what() << std::endl;
		// OUTPUT:
		// Logger name cannot have escape characters
	}

	return 0;
}