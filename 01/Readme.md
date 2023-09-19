# README

Knowledge test of 𝙎𝙩𝙤𝙧𝙬𝙚𝙡𝙡
https://www.𝙎𝙩𝙤𝙧𝙬𝙚𝙡𝙡.com/careers/software-developer

## Quiz 1

Write a function in C that takes the inputs N, and M, and returns the series
of squares that can be made out of that piece of paper. No fractional squares,
i.e. no square should be less than 1 in length and width.

### Answer

We could simply use Greedy Algorithm to solve problems.

Please reference the soure codes in `Q1/`

## Quiz 2

### 2.a)

First task is to find function f(Ai) using these sets of points in the spreadsheet.

Attached spreadsheet: [HERE](https://docs.google.com/spreadsheets/d/1MmruzOui-GdlbqTF2s74VERX_5c_eT2VkXhGK5BUDUg/edit#gid=0)

#### Answer

f(Ai) is a function that converts decimal numbers to 62-based numbers. The
62 symbols include 0 to 9, a to z, and A to Z. However, the order of these
symbols is not sequential like 0, 1, 2, 3, etc., so we need to determine the
correct sequence among these symbols.

As Ai and y have a one-to-one relationship, we can easily reconstruct the
mapping table generated by the `quiz2.c` program using a spreadsheet.

The mapping table is as below:

```
0=C,    1=7,    2=x,    3=i,    4=c,    5=P,    6=M,    7=G,
8=v,    9=z,    10=A,   11=Z,   12=y,   13=T,   14=N,   15=o,
16=d,   17=m,   18=w,   19=n,   20=V,   21=5,   22=D,   23=3,
24=B,   25=6,   26=H,   27=0,   28=O,   29=u,   30=p,   31=8,
32=E,   33=2,   34=1,   35=W,   36=9,   37=s,   38=q,   39=L,
40=Q,   41=X,   42=4,   43=Y,   44=j,   45=S,   46=e,   47=U,
48=h,   49=I,   50=R,   51=J,   52=g,   53=a,   54=f,   55=F,
56=t,   57=r,   58=K,   59=l,   60=b,   61=k,
```

### 2.b)

What would be the output for the following inputs?
1. 𝒇（３０００１） = ?
2. 𝑓（５５５５５） = ?
3. 𝒇（７７７８８） = ?

#### Answer

1. 𝒇（３０００１） = GIF
2. 𝑓（５５５５５） = NOi
3. 𝒇（７７７８８） = VNQ

### 2.c)

What is the upper limit or maximum range of this function before there will be
collisions or overflow?

#### Answer

There is no upper limit or maximum range in this function before any collisions
or overflow.

### 2.d)

Please share any code that you write in the process of solving the above
problems.

#### Answer

Please reference the soure codes in `Q2/`