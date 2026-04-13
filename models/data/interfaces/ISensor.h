//
// Created by Hugo on 13/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_ISENSOR_H
#define CARENTERTAINMENTSYSTEM_ISENSOR_H



class ISensor {
public:
    virtual float getData() = 0;
    virtual ~ISensor() = default;
};



#endif //CARENTERTAINMENTSYSTEM_ISENSOR_H
