program pku1007;
type dna=record s:string;num,so:longint;end;
var n,m,i,j,k:longint;
    a:array[1..100]of dna;dd:dna;
begin
  //assign(input,'pku1007.in');reset(input);
  repeat
  readln(n,m);
  for i:=1 to m do
    with a[i] do begin
    num:=i;
    readln(s);
    end;
  for i:=1 to m do
    with a[i] do begin
    so:=0;
    for j:=1 to n-1 do
      for k:=j+1 to n do
        if s[j]>s[k] then inc(so);
    end;
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if a[i].so>a[j].so then begin
        dd:=a[i];a[i]:=a[j];a[j]:=dd;
        end;
  for i:=1 to m do
    writeln(a[i].s);
  until seekeof;
end.