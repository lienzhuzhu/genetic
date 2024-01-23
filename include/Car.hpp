/* 
 * Car class declaration
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <raylib/raylib.h>
#include "Track.hpp"

#define CAR_WIDTH   30.f
#define CAR_LENGTH  60.f

class Car {
public:
    Car() = default;
    Car(Track *track);
    Car(Car &&) = default;
    Car(const Car &) = default;
    Car &operator=(Car &&) = default;
    Car &operator=(const Car &) = default;
    ~Car() = default;

    void update(double dt);
    void render(double remainder);
    void set_prev_state(void);
    Vector2 get_center(void);

private:
    typedef struct {
        Vector2 center;
        float steering_angle;
    } Car_State;

    Track *_track;
    Car_State _curr_state;
    Car_State _prev_state; // for render interpolation
    Rectangle _body;
    Color _color;
};

#endif // !CAR_HPP
