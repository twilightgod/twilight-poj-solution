program pku4i;
var min,u,i,j,k,n,t,l:longint;
    v:array[0..2000]of boolean;
    dis:array[0..2000,0..2000]of longint;
    d:array[0..2000]of longint;
begin
  repeat
  fillchar(v,sizeof(v),false);
  fillchar(d,sizeof(d),$7f);
  fillchar(dis,sizeof(dis),$7f);
  d[1]:=0;
  readln(t,n);
  for i:=1 to n do begin
    readln(j,k,l);
    if dis[j,k]>l then begin dis[j,k]:=l;dis[k,j]:=l; end;
    end;
  repeat
  min:=maxlongint;
  u:=-1;
  for i:=1 to t do
    if (v[i]=false) and (d[i]<min) then begin u:=i;min:=d[i];end;
  if u=t then break;
  v[u]:=true;
  for i:=1 to t do
    if (v[i]=false) and (dis[i,u]+d[u]<d[i]) then d[i]:=dis[i,u]+d[u];
  until u=-1;
  writeln(d[t]);
  until seekeof;
end.
