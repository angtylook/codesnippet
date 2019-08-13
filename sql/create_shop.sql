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



