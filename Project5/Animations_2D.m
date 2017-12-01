%% 2D Animation
%Upload the file Final_results2D.mat, where you find the results.
%Run each section to see the animated wave from 0 to 150 time.
%Made by Ingvild, Hanne and Ola in November/Desember 2017


%% Sinus wave in bounded domain (basin)
figure(1)

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);

for i = 1:10:(150*40)
       
       surf(X,Y,BSIN2D(((i - 1)*41 +1):(i*41),1:41));
       zlim([-2,2])
       drawnow limitrate
       
end

%% Sinus wave in periodic domain
figure(2)

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);

for i = 1:10:(150*40)
       
       surf(X,Y,PSIN2D(((i - 1)*41 +1):(i*41),1:41));
       zlim([-2,2])
       drawnow limitrate
       
end


%% Gaussian wave in bounded domain
figure(3)

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);

for i = 1:10:(150*40)
       
       surf(X,Y,BEXP2D(((i - 1)*41 +1):(i*41),1:41));
       zlim([-2,2])
       drawnow limitrate
       
end

%% Gaussian wave in periodic domain
figure(4)

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);

for i = 1:10:(150*40)
       
       surf(X,Y,PEXP2D(((i - 1)*41 +1):(i*41),1:41));
       zlim([-2,2])
       drawnow limitrate
       
end