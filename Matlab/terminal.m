%------------------------------------------------------
%  Initialize variables.
%
%  Variables Kp, Ti and Td are being calculated according to the
%  ziegler-nichols method.
%------------------------------------------------------
COMPORT = 'COM4';
BAUDRATE = 115200; 
receivedValue = 0; % Value recieved via serial communication
Kc = 0; % Critical gain of system 
Pc = 0; % Oscillation period of system
Kp = 0.65 * Kc; % Controller path gain
Ti = 0.5 * Pc; % Controller integrator time constant
Td = 0.12 * Pc; % Controller derivator time constant
dT = 0;
target = 0; % Target location for ball.
errorValue; % Distance between ball and target distance
currentValue; % Location of the ball

%------------------------------------------------------
%   Communications-protocol
%
%   Values wich when sent indicates what the following value being sent
%   represents.
%------------------------------------------------------
com_target = 11;
com_Kp = 22;
com_Ti = 33;
com_Td = 44;
com_dT = 55;
com_errorValue = 66;
com_currentValue = 77;

%------------------------------------------------------
%  Establish serial communication.
%------------------------------------------------------
s1 = serial(COMPORT, 'baudrate', BAUDRATE);
set(s1, 'Terminator', 10);
fopen(s1);

%------------------------------------------------------
%   Transmit information to arduino.
%------------------------------------------------------
fwrite(s1, com_target, 'uchar');
fwrite(s1, target, 'uchar');
fwrite(s1, com_Kp, 'uchar');
fwrite(s1, Kp, 'uchar');
fwrite(s1, com_Ti, 'uchar');
fwrite(s1, Ti, 'uchar');
fwrite(s1, com_Td, 'uchar');
fwrite(s1, Td, 'uchar');
fwrite(s1, com_dT, 'uchar');
fwrite(s1, dT, 'uchar');

%------------------------------------------------------
%  Recieve information from arduino
%------------------------------------------------------
while(1)
    receivedValue = fscanf(s1, '&u');

    if(receivedValue == com_errorValue)
        errorValue = fscanf(s1, '&u');
    elseif (reciedValue == com_currentValue)
        currentValue = fscanf(s1, '&u');
    end

    flushinput(s1);
    flushoutput(s1);
end