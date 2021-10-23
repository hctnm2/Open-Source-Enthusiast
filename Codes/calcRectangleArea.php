<?php

class Calculate {
    public function calcRectangleArea($length, $width){
        $area = $length * $width;
        return $area;
    }
}

$rect = new Calculate;
echo $rect->calcRectangleArea(6,3);