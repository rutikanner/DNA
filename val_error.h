//
// Created by ruti on 6/4/20.
//

#ifndef DNASEQUENCE_VAL_ERROR_H
#define DNASEQUENCE_VAL_ERROR_H

#include <stdexcept>

class ValError : public std::runtime_error{
public:
    ValError(const std::string& message);
};

inline ValError::ValError(const std::string &message): std::runtime_error(message)  {}
#endif //DNASEQUENCE_VAL_ERROR_H
