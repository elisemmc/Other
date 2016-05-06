function [perimeter, area] = Calculate_AP(sides)
disp('1 Circle')
disp('2 Triangle')
disp('3 Pentagon')
disp('4 Hexagon')
shape = input('Please enter the number corresponding to the shape:');
if shape == 1
    perimeter = 2*pi*sides(1);
    area = pi*sides(1)^2;
elseif shape == 2
        if length(sides)== 3
            perimeter = sum(sides);
            area = (1/4)*sqrt(-sides(1)^4+2*(sides(1)*sides(2))^2+2*(sides(1)*sides(3))^2-sides(2)^4+2*(sides(2)*sides(3))^2-sides(3)^4);
        elseif length(sides)== 1;
            perimeter = sides*3;
            area = (sqrt(3)/4)*sides(1)^2;
        else
            disp('error')
        end
elseif shape == 3
    perimeter = 5 * sides(1);
    area = (1/4)*sqrt(5*(5+2*sqrt(5)))*sides(1)^2;
elseif shape == 4
    perimeter = 6 * sides(1);
    area = ((3*sqrt(3))/2)*sides(1)^2;
else
    disp('error')
end
