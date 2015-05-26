program pku2311;
var w,h,k:longint;
begin
  repeat
  readln(w,h);
  k:=trunc(ln(w*h)/ln(2));
  if odd(k) then writeln('WIN') else writeln('LOSE');
  until seekeof;
end.