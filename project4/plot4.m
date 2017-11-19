%% Project4 FYS4150 plotting in matlab

%Made for project 4 in FYS4150
%Made by Ingvild and Ola

% Used matlabs import data "button" to get the data!
% All relevant data are stored in project4data.mat
% Upload this to do the plotting

%% Oppgave 4c) del 1
%Using the values which were printed, number of flips accepted pr mcc.

Temp = [1, 1.5, 2.4];
AcceptedU = [0.29005, 5.35361, 107.842];
AcceptedR = [0.292448, 5.6415, 107.65];

fig69 = figure(69)
plot(Temp, AcceptedU)
hold on
plot(Temp, AcceptedR)
legend(['All up init. config'] ,['random init. config'])
title('Accepted flips pr MCC vs Temp')
xlabel('Temperature')
ylabel('Accepted flips pr MCC')


%% Oppgave 4c)

%---------- T = 1, R & U ------------------ENERGY --------------
fig1 = figure(1);
subplot(1,2,1)
plot(c_E1U)
hold on
plot(c_E1R)
title('<E> vs MCS, T = 1')
legend(['All up init. config'],['Random init. config'])
ylabel('<E>')
xlabel('# MCS')
ylim([-1.9972 -1.9968])
xlim([0 8000000])

%---------- T = 1, R & U ----------------- |Magnetizm| --------------
subplot(1,2,2)
plot(c_M1U)
hold on
plot(c_M1R)
title('<|M|> vs MCS, T = 1')
legend(['All up init. config'],['Random init. config'])
ylabel('<|M|>')
xlabel('# MCS')
ylim([0.99915 0.9993])
xlim([0 8000000])
%%
%-------------- T = 2.4, R & U ------------------ Energy ---------
fig2 = figure(2);
subplot(1,2,1)
plot(c_E24U)
hold on
plot(c_E24R)
title('<E> vs MCS, T = 2.4')
legend(['All up init. config'],['Random init. config'])
ylabel('<E>')
xlabel('# MCS')
ylim([-1.25 -1.23])
xlim([0 8000000])



%-------------- T = 2.4, R & U -------------|Magnetizm| ------------
subplot(1,2,2)
plot(c_M24U)
hold on
plot(c_M24R)
title('<|M|> vs MCS, T = 2.4')
legend(['All up init. config'],['Random init. config'])
ylabel('<|M|>')
xlabel('# MCS')
ylim([0.44 0.475])
xlim([0 8000010])




%% Oppgave 4d)
%Use the 4M last mcs values since they are from the equlibrium realm.

%Plot 
fig3 = figure(3);
subplot(1,2,1)
histogram(c_E1R(5000000:8000000))
title('<E> at T = 1')
ylabel('# of <E> values pr interval')

%Plot as normal for comparison
subplot(1,2,2)
plot(c_E1R(5000000:8000000))
title('<E> vs MCS, T = 1')
ylabel('<E>')
xlabel('#MCS after equlibrium is reached')
%ylim([-1.998 -1.994])
xlim([0 3000010])

%Plot 
fig4 = figure(4);
subplot(1,2,1)
histogram(c_E24R(5000000:8000000))
title('<E> values at T = 2.4')
ylabel('# of <E> values pr interval')

%Plot as normal for comparison
subplot(1,2,2)
plot(c_E24R(5000000:8000000))
title('<E> vs MCS, T = 2.4')
ylabel('<E>')
xlabel('#MCS after equlibrium is reached')
%ylim([-1.998 -1.994])
xlim([0 3000010])

%Standard deviation sqrt(Cv/T²)  Much larger than what we get.
%Maybe because we use all values to calculate Cv and thus get a bigger
%sigma than what is "useful" for our numbers.



%% Oppgave 4e)

% Energy for different T's and different L sizes
fig5 = figure(5);
plot(e_T20U, e_E20U)
hold on
plot(e_T40U, e_E40U)
plot(e_T60U, e_E60U)
plot(e_T80U, e_E80U)
plot(e_T80U, e_E100U)
title('<E> vs Temperature')
ylabel('<E>')
xlabel('Temperature')
legend('L20','L40', 'L60', 'L80', 'L100')

%Cv for different T's and different L sizes
fig6 = figure(6);
plot(e_T20U, e_Cv20U)
hold on
plot(e_T40U, e_Cv40U)
plot(e_T60U, e_Cv60U)
plot(e_T80U, e_Cv80U)
plot(e_T80U, e_Cv100U)
title('Cv vs Temperature')
ylabel('Cv')
xlabel('Temperature')
legend('L20','L40', 'L60', 'L80','L100')

%Xsi for different temperatures and different L sizes
fig7 = figure(7);
plot(e_T20U, e_X20U)
hold on
plot(e_T40U, e_X40U)
plot(e_T60U, e_X60U)
plot(e_T80U, e_X80U)
plot(e_T80U, e_X100U)
title('Xsi vs Temperature')
ylabel('Xsi')
xlabel('Temperature')
legend('L20','L40', 'L60', 'L80','L100')

fig8 = figure(8);
plot(e_T20U, e_Mabs20U)
hold on
plot(e_T40U, e_Mabs40U)
plot(e_T60U, e_Mabs60U)
plot(e_T80U, e_Mabs80U)
plot(e_T80U, e_Mabs100U)
title('<|M|> vs Temperature')
ylabel('<|M|>')
xlabel('Temperature')
legend('L20', 'L40', 'L60', 'L80','L100')
