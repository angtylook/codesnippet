create table Product (
pro_id char(4) not null,
pro_name varchar(100) not null,
pro_cat varchar(32) not null,
pro_price integer,
pro_in_price integer,
pro_date date,
primary key (pro_id)
);

insert into Product values('0001', 'T恤衫', '衣服', 1000, 500, '2009-09-20');
insert into Product values('0002', '打孔器', '办公用品', 500, 320, '2009-09-11');
insert into Product values('0003', '运动T恤', '衣服', 4000, 2800, NULL);
insert into Product values('0004', '菜刀', '厨房用品', 3000, 2800, '2009-09-20');
insert into Product values('0005', '高压锅', '厨房用品', 6800, 5000, '2009-01-15');
insert into Product values('0006', '叉子', '厨房用品', 500, NULL, '2009-09-20');
insert into Product values('0007', '擦菜板', '厨房用品', 880, 790, '2008-04-28');
insert into Product values('0008', '圆珠笔', '办公用品', 100, NULL, '2009-11-11');

create table shohinins (
shohin_id char(4) not null,
shohin_mei varchar(100) not null,
shohin_bunrui varchar(32) not null,
hanbai_tanka integer default 0,
shiire_tanka integer,
torokubi date,
primary key (shohin_id)
);

insert into shohinins (shohin_id, shohin_mei, shohin_bunrui, hanbai_tanka, shiire_tanka, torokubi) values('0001', 'T恤衫', '衣服', 1000, 500, '2009-09-20');
insert into shohinins values('0005', '高压锅', '厨房用品', 6800, 5000, '2009-01-15');
insert into shohinins values('0006', '叉子', '厨房用品', 500, NULL, '2009-09-20');
insert into shohinins values('0007', '擦菜板', '厨房用品', default, 790, '2008-04-28');

create table shohin (
shohin_id char(4) not null,
shohin_mei varchar(100) not null,
shohin_bunrui varchar(32) not null,
hanbai_tanka integer,
shiire_tanka integer,
torokubi date,
primary key (shohin_id)
);

insert into shohin (shohin_id, shohin_mei, shohin_bunrui, hanbai_tanka, shiire_tanka, torokubi)
select pro_id, pro_name, pro_cat, pro_price, pro_in_price, pro_date from product;

create view shohinsum (shohin_bunrui, cnt_shohin) as select shohin_bunrui, count(*) from shohin group by shohin_bunrui;

select shohin_bunrui, cnt_shohin
from (select shohin_bunrui, count(*) as cnt_shohin from shohin group by shohin_bunrui) as shohinsum;

select shohin_id, shohin_mei, hanbai_tanka
from shohin
where hanbai_tanka > (select avg(hanbai_tanka) from shohin);

select shohin_id, shohin_mei, hanbai_tanka
from shohin as s1
where hanbai_tanka > (select avg(hanbai_tanka) from shohin as s2
    where s1.shohin_bunrui = s2.shohin_bunrui
    group by shohin_bunrui);

create table SampleMath(m NUMERIC (10,3), n INTEGER, p INTEGER);
insert into SampleMath(m, n, p) values(500, 0, NULL);
insert into SampleMath(m, n, p) values(-180, 0, NULL);
insert into SampleMath(m, n, p) values(NULL, NULL, NULL);
insert into SampleMath(m, n, p) values(NULL, 7, 3);
insert into SampleMath(m, n, p) values(NULL, 5, 2);
insert into SampleMath(m, n, p) values(NULL, 4, NULL);
insert into SampleMath(m, n, p) values(8, NULL, 3);
insert into SampleMath(m, n, p) values(2.27, 1, NULL);
insert into SampleMath(m, n, p) values(5.555, 2, NULL);
insert into SampleMath(m, n, p) values(NULL, 1, NULL);
insert into SampleMath(m, n, p) values(8.76, NULL, NULL);

create table SampleStr (
    str1 varchar(40),
    str2 varchar(40),
    str3 varchar(40)
);

insert into SampleStr(str1, str2, str3) values('opx', 'rt', NULL);
insert into SampleStr(str1, str2, str3) values('abc', 'def', NULL);
insert into SampleStr(str1, str2, str3) values('山田', '太郎', '是我');
insert into SampleStr(str1, str2, str3) values(NULL, 'xyz', NULL);
insert into SampleStr(str1, str2, str3) values('@!#$%', NULL, NULL);
insert into SampleStr(str1, str2, str3) values('ABC', NULL, NULL);
insert into SampleStr(str1, str2, str3) values('aBC', NULL, NULL);
insert into SampleStr(str1, str2, str3) values('abc太郎', 'abc', 'ABC');
insert into SampleStr(str1, str2, str3) values('abcdefabc', 'abc', 'ABC');
insert into SampleStr(str1, str2, str3) values('micmic', 'i', 'I');

select shohin_mei, hanbai_tanka from shohin where hanbai_tanka between 100 and 1000;
select shohin_mei, hanbai_tanka from shohin where shiire_between in (320, 500, 5000);

create table shohin2 (
shohin_id char(4) not null,
shohin_mei varchar(100) not null,
shohin_bunrui varchar(32) not null,
hanbai_tanka integer,
shiire_tanka integer,
torokubi date,
primary key (shohin_id)
);
insert into shohin2 values('0001', 'T恤衫', '衣服', 1000, 500, '2009-09-20');
insert into shohin2 values('0002', '打孔器', '办公用品', 500, 320, '2009-09-11');
insert into shohin2 values('0003', '运动T恤', '衣服', 4000, 2800, NULL);
insert into shohin2 values('0009', '手套', '衣服', 800, 500, NULL);
insert into shohin2 values('0010', '水壶', '厨房用品', 2000, 1700, '2009-09-20');

create table tenposhohin(
    tenpo_id char(4) not null,
    tenpo_mei varchar(200) not null,
    shohin_id char(4) not null,
    suryo integer not null,
    primary key (tenpo_id, shohin_id)
);

insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000A', '东京', '0001', 30);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000A', '东京', '0002', 50);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000A', '东京', '0003', 15);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000B', '名古屋', '0002', 30);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000B', '名古屋', '0003', 120);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000B', '名古屋', '0004', 20);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000B', '名古屋', '0006', 10);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000B', '名古屋', '0007', 40);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000C', '大阪', '0003', 20);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000C', '大阪', '0004', 50);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000C', '大阪', '0006', 90);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000C', '大阪', '0007', 70);
insert into tenposhohin(tenpo_id, tenpo_mei, shohin_id, suryo) values('000D', '福冈', '0001', 100);

select ts.tenpo_id, ts.tenpo_mei, ts.shohin_id, s.shohin_mei, s.hanbai_tanka
from tenposhohin as ts
inner join shohin as s
on ts.shohin_id = s.shohin_id;

select ts.tenpo_id, ts.tenpo_mei, ts.shohin_id, s.shohin_mei, s.hanbai_tanka
from tenposhohin as ts
right join shohin as s
on ts.shohin_id = s.shohin_id;

select ts.tenpo_id, ts.tenpo_mei, ts.shohin_id, s.shohin_mei
from tenposhohin as ts cross join shohin as s;
