//
//  CustomException.hpp
//  City Map
//
//  Created by Kaloyan Dimov on 15.05.22.
//

#ifndef CustomException_hpp
#define CustomException_hpp

#include <stdexcept>

class CustomException : public std::logic_error {
 public:
    CustomException(const std::string&);
    
    char const* what() const noexcept override;
};

#endif /* CustomException_hpp */
