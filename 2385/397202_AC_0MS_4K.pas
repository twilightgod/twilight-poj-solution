program tju1128;
const
  maxw=30;
var
  get:array[boolean,0..maxw]of word;
  t,w,i,j,x:word;
function max(a,b:word):word;
  begin
    if a>b then max:=a else max:=b;
  end;
begin
  repeat
    fillchar(get,sizeof(get),0);
    read(t,w);
    for i:=1 to t do begin
      read(x);dec(x);
      get[odd(i),0]:=get[not odd(i),0]+ord(x=0);
      for j:=1 to w do
        get[odd(i),j]:=max(get[not odd(i),j],get[not odd(i),j-1])+ord(j mod 2=x);
    end;
    x:=0;
    for i:=0 to w do
      if get[odd(t),i]>x then x:=get[odd(t),i];
    writeln(x);
  until seekeof;
end.
