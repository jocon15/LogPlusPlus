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
	return 0;
}