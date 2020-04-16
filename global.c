/*
** EPITECH PROJECT, 2020
** william
** File description:
** global
*/

#include "lib/struckt.h"

struct gb *mglobal(void) 
{ 
    static glb global[1]; 
    return (global);
}
