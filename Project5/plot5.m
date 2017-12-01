%Plotting in project 5
%Based on the data in FINALDATA.mat

%% Animation of Psi as function of time with solid boundaries with sin init
%Different timesteps 0.001 0.025 0.5

figure(1)
psi1 = reshape(sigma01.psi,41,(100*150));
psi2 = reshape(sigma1.psi,41,(100*150));
%psi3 = reshape(BSINC1D10.psi,41,(15));


figure(1)
for i = 1:length(psi1)

    plot(0:40,psi1(:,i),'blue');
    ylim([-50,50]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    
end

figure(2)
for i = 1:length(psi2)  

    plot(0:40,psi2(:,i),'blue');
    ylim([-0.1,0.1]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    
end

%figure(3)
%for i = 1:length(psi3)  
%
 %   plot(0:40,psi3(:,i),'blue');
  %  ylim([-20,20]);
   % xlim([0,40]);
    %grid on
    %drawnow limitrate 
    


%% Figure for oppgave 5e)
psi1 = reshape(BSINF1D001.psi,41,(1000*150));
psi2 = reshape(BSINF1D025.psi,41,(40*150));
psi3 = reshape(BSINF1D1.psi,41,(150));
psi4 = reshape(BSINF1D001.psi,41,(1000*150));
psi5 = reshape(BSINC1D025.psi,41,(40*150));
psi6 = reshape(BSINC1D1.psi,41,(150));
psi7 = reshape(BSINC1D5.psi,41,(2*150));
psi8 = reshape(BSINF1D5.psi,41,(2*150));

figure(88)
subplot(2,2,1)
plot(0:(1/40):1,psi1(:,150000),'-');
hold on
plot(0:(1/40):1,psi4(:,150000),'--');
ylim([-4 4]);
legend('forward diff', 'centered diff')
title('dt = 0.001')
hold off

subplot(2,2,2)
plot(0:(1/40):1,psi2(:,(4*150)));
hold on
plot(0:(1/40):1,psi5(:,(4*150)));
ylim([-4 4]);
legend('forward', 'centered')
title('dt = 0.025')
hold off

subplot(2,2,3)
plot(0:(1/40):1,psi7(:,150));
hold on
plot(0:(1/40):1,psi8(:,150));
ylim([-4 4]);
legend('forward', 'centered')
title('dt = 0.5')
hold off

subplot(2,2,4)
plot(0:(1/40):1,psi3(:,150));
hold on
plot(0:(1/40):1,psi6(:,150));
ylim([-4 4]);
legend('forward', 'centered')
title('dt = 1')
hold off




%% Animation of Psi as function of time with p-boundaries with exp init

figure(2)
psi3 = reshape(expforwardperiodic.psi,41,(40*150));
psi4 = reshape(expcenteredperiodic.psi,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,psi3(:,i),'blue');
    ylim([-2,2]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,psi4(:,i),'blue');
    ylim([-2,2]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Animation of Psi as function of time with solid boundaries with sin init

figure(3)
psi5 = reshape(sinforwardsolid.psi,41,(40*150));
psi6 = reshape(sincenteredsolid.psi,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,psi5(:,i),'blue');
    ylim([-2,2]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,psi6(:,i),'blue');
    ylim([-2,2]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Animation of Psi as function of time with p-boundaries with sin init

figure(4)
psi7 = reshape(sinforwardperiodic.psi,41,(40*150));
psi8 = reshape(sincenteredperiodic.psi,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,psi7(:,i),'blue');
    ylim([-2,2]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,psi8(:,i),'blue');
    ylim([-2,2]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Animation of Vorticity with solid boundaries with exp init

figure(5)
y1 = reshape(expforwardsolid.E07,41,(40*150));
y2 = reshape(expcenteredsolid.vorticity,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,y1(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,y2(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Animation of Vorticity with p-boundaries with exp init

figure(6)
y1 = reshape(expforwardperiodic.vorticity,41,(40*150));
y2 = reshape(expcenteredperiodic.vorticity,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,y1(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,y2(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Animation of Vorticity with solid boundaries with sin init

figure(7)
y1 = reshape(sinforwardsolid.vorticity,41,(40*150));
y2 = reshape(sincenteredsolid.vorticity,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,y1(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,y2(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Animation of Vorticity with p-boundaries with sin init

figure(8)
y1 = reshape(sinforwardperiodic.vorticity,41,(40*150));
y2 = reshape(sincenteredperiodic.vortcity,41,(40*150));

for i = 1:6000
    subplot(1,2,1)
    plot(0:40,y1(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate
    

    subplot(1,2,2)
    plot(0:40,y2(:,i),'blue');
    ylim([-200,200]);
    xlim([0,40]);
    grid on
    drawnow limitrate 
    
end

%% Hovmueller diagram for the different cases

%% Oppgave 5f - a - sine in periodic domain

%Setting up the "hovmueller" grid 
[X,Y] = meshgrid((0:(1/40):1),(0:(1/100):(150-0.001)));

figure(10)
psi7 = reshape(PSINCAR1D01.psi,41,(100*150));
hovb1 = psi7';
contourf(X,Y,hovb1)
xlabel('x - position');
ylabel('Time');
colorbar

%% Oppgave 5f - ab - sine in periodic and bounded domain

%Setting up the "hovmueller" grid 
[X,Y] = meshgrid((0:(1/40):1),(0:(1/100):(150-0.001)));
psi7 = reshape(PSINCAR1D01.psi,41,(100*150));
hovb1 = psi7';

figure(10)
subplot(1,2,1)
contourf(X,Y,hovb1)
xlabel('x - position');
ylabel('Time');

%Setting up the next "hovmueller" grid 
psi8 = reshape(BSINC1D01.psi,41,(100*150));
 
hova1 = psi8';
subplot(1,2,2)
title('bounded domain')
contourf(X,Y,hova1)


%% Oppgave 5f - cd - exp

%Setting up the "hovmueller" grid 
[X,Y] = meshgrid((0:(1/40):1),(0:(1/100):(150-0.001)));
psi7 = reshape(PEXPCAR1D01.psi,41,(100*150));
hovb1 = psi7';

figure(10)
subplot(1,2,1)
contourf(X,Y,hovb1)
xlabel('x - position');
ylabel('Time');

%Next psi
psi8 = reshape(BEXPC1D01.psi,41,(100*150));
 
hova1 = psi8';
subplot(1,2,2)
title('bounded domain')
contourf(X,Y,hova1)

%% Oppgave 5f - four different sigmaz

%Setting up the "hovmueller" grid 
[X,Y] = meshgrid((0:(1/40):1),(0:(1/100):(150-0.001)));
psi7 = reshape(PEXPCAR1D01.psi,41,(100*150));
hovb1 = psi7';

figure(10)
subplot(1,2,2)
contourf(X,Y,hovb1)
xlabel('x - position');
title('sigma = 0.1')

%Next psi
psi8 = reshape(sigma01.psi,41,(100*150));
 
hova1 = psi8';
subplot(1,2,1)
contourf(X,Y,hova1)
title('sigma = 0.01')
ylabel('time');

%Next psi
figure(11)
psi8 = reshape(sigma05.psi,41,(100*150));
 
hova1 = psi8';
subplot(1,2,1)
contourf(X,Y,hova1)
caxis([min(min(hova1)) max(max(hova1))])
ylabel('time')
xlabel('x-position')
title('sigma = 0.5')

%Next psi
psi8 = reshape(sigma1.psi,41,(100*150));
 
hova1 = psi8';
subplot(1,2,2)
contourf(X,Y,hova1)
caxis([-0.014 0.014])
title('sigma = 1')

%%
hovb2 = psi8';
subplot(1,2,2)
contourf(X,Y,hovb2)

%Oppgave 5f - c1 - exp in periodic domain, sigma = 0.1
figure(11)
hovc11 = psi3';
subplot(1,2,1)
contourf(X,Y,hovc11)

hovc12 = psi4';
subplot(1,2,2)
contourf(X,Y,hovc12)

%Oppgave 5f - c2 - exp in periodic domain, sigma = xxx

%Oppgave 5f - d - exp in bounded domain, sigma = 0.1
figure(12)
hovd1 = psi1';
subplot(1,2,1)
contourf(X,Y,hovd1)

hovd2 = psi2';
subplot(1,2,2)
contourf(X,Y,hovd2)

%% 2D Animation bounded domain

figure(13)

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);

for i = 1:5:(150*40)
       
       surf(X,Y,BSIN2D(((i - 1)*41 +1):(i*41),1:41));
       zlim([-2,2])
       drawnow limitrate
       
end

%% 2D Animation periodic domain
figure(14)

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);

for i = 1:10:(150*40)
       
       surf(X,Y,PEXP2D(((i - 1)*41 +1):(i*41),1:41));
       zlim([-2,2])
       drawnow limitrate
       
end

%% Plot 5g SIN

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);
figure(888)

for i = 0:2
    
    subplot(3,2,i*2 + 1)
    surf(X,Y,BSIN2D((7*41*i*100 + 1):(7*41*i*100 + 41),1:41))
    zlim([-2,2])
    xlabel('x')
    ylabel('y')
    zlabel('z')
    if(i == 0)
        title('Basin')
        zlabel('tid = 0')
        set(get(gca,'zlabel'),'rotation',0)
    end
    if(i == 1)
        zlabel('tid = 7')
        set(get(gca,'zlabel'),'rotation',0)
    end
    if(i == 2)
        zlabel('tid = 14')
        set(get(gca,'zlabel'),'rotation',0)
    end

end

for i = 0:2

    subplot(3,2,i*2 + 2)
    surf(X,Y,PSIN2D((7*41*i*100 + 1):(7*41*i*100 + 41),1:41))
    zlim([-2,2])
    xlabel('x')
    ylabel('y')
    zlabel('z')
    if(i == 0)
        title('Periodic')
    end
    

end

%% Plot 5g - EXP

%Mekke matrisegreier
[X,Y] = meshgrid(0:(1/40):1,0:(1/40):1);
figure(888)

for i = 0:2
    
    subplot(3,2,i*2 + 1)
    surf(X,Y,BEXP2D((15*41*i*100 + 1):(15*41*i*100 + 41),1:41))
    zlim([-2,2])
    xlabel('x')
    ylabel('y')
    zlabel('z')
    if(i == 0)
        title('Basin')
        zlabel('tid = 0')
        set(get(gca,'zlabel'),'rotation',0)
    end
    if(i == 1)
        zlabel('tid = 15')
        set(get(gca,'zlabel'),'rotation',0)
    end
    if(i == 2)
        zlabel('tid = 30')
        set(get(gca,'zlabel'),'rotation',0)
    end

end

for i = 0:2

    subplot(3,2,i*2 + 2)
    surf(X,Y,PEXP2D((15*41*i*100 + 1):(15*41*i*100 + 41),1:41))
    zlim([-2,2])
    xlabel('x')
    ylabel('y')
    zlabel('z')
    if(i == 0)
        title('Periodic')
    end
    

end