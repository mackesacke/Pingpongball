COMPORT = 'COM4';
BAUDRATE = 115200;
s1 = serial(COMPORT, 'baudrate', BAUDRATE);
set(s1, 'Terminator', 10);
fopen(s1);
adc = zeros(1,1);
N = 250;
values = zeros(1, N);
for n = 1:N
   adc = fscanf(s1);
   values{n} = adc;
   flushinput(s1);
   flushoutput(s1);
end
x = linspace(0, 250);
plot(x, n);