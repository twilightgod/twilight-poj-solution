program pku4l;
var m,y,i:longint;sum,r:extended;
begin
  repeat
  readln(r,m,y);
  sum:=m;
  r:=1+r/100;
  for i:=1 to y do
    sum:=sum*r;
  writeln(trunc(sum));
  until seekeof;
end.