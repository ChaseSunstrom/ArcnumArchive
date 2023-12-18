#include "game/arcnum.h"

int main(void)
{
	//                             x         y       z        w
    quat rotation_quaternion = {1.0, 1.0, 1.0, 0.0 };  
    vec3 input_vector = {3, 1.0f, 0.0f, 0.0f };

    printf("Input vector: (%f, %f, %f)\n", input_vector.x, input_vector.y, input_vector.z);
    // Multiply the quaternion by the vector
   vec3_rotate(rotation_quaternion, &input_vector);
	printf("Input vector: (%f, %f, %f)\n", input_vector.x, input_vector.y, input_vector.z);
}
