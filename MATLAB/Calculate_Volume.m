function volume = Calculate_Volume(side)
disp('1 Sphere')
disp('2 Cylinder')
disp('3 Right Cone')
disp('4 Cube')
shape = input('Please enter the number corresponding to the shape:');
if shape == 1
    volume = (4/3)*pi*side(1)^3;
elseif shape == 2
    if length(side)==1
        height = input ('What is the height of the cylinder?');
    else
        height = side(2);
    end
    volume = pi*side(1)^2*height;
elseif shape == 3
    if length(side)>=2
        height = side(2);
    else
        height = input ('What is the height of the cone?');
    end
    volume = pi*side(1)^2*(height/3);
elseif shape == 4
    volume = side(1)^3;
else
    disp('error')
end
