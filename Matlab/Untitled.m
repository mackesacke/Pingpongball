n = 250;
bla = cell(1, n);
bla2 = zeros(1, n);
adc = 0;
for N = 0:n
    bla{n} = adc;
    adc = adc + 1;
    bla2(n) = cell2mat(bla(n));
end
x = linspace(0, 250);
plot(bla2(n))   