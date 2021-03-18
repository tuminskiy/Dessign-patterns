#include "impl.hpp"

#include <mutex>
#include <iostream>
#include <cassert>

// LoggerImpl

class LoggerImpl
{
  std::mutex mtx_;
  size_t error_count_;

public:
  void log_error(std::string_view sv)
  {
    std::lock_guard lg(mtx_);
    std::cout << "ERROR: " << sv << std::endl;
    ++error_count_;
  }

  void log_info(std::string_view sv)
  {
    std::lock_guard lg(mtx_);
    std::cout << "INFO: " << sv << std::endl;
  }

  size_t error_count() const { return error_count_; }
};


// Logger

LoggerImpl& Logger::impl()
{
  static LoggerImpl impl;
  return impl;
}

void Logger::log_error(std::string_view sv) { impl().log_error(sv); }

void Logger::log_info(std::string_view sv) { impl().log_info(sv); }

size_t Logger::error_count() const { return impl().error_count(); }



int main()
{
  {
    Logger log1;
    log1.log_error("Segmentation fault");
  }

  Logger{}.log_info("Success connect to database");

  Logger{}.log_error("Failed open file");

  assert(Logger{}.error_count() == 2); // TRUE
}