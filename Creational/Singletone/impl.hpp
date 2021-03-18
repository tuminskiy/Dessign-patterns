#pragma once

#include <string_view>

class LoggerImpl;

class Logger
{
  static LoggerImpl& impl();

public:
  Logger() = default;
  
  Logger(const Logger&) = delete;
  Logger(Logger&&) = delete;

  Logger& operator= (const Logger&) = delete;
  Logger& operator= (Logger&&) = delete;

  void log_error(std::string_view sv);
  void log_info(std::string_view sv);

  size_t error_count() const;
};