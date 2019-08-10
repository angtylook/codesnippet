create table Product (
pro_id char(4) not null,
pro_name varchar(100) not null,
pro_cat varchar(32) not null,
pro_price integer,
pro_in_price integer,
pro_date date,
primary key (pro_id)
);

insert into Product values('0001', 'T恤衫', '衣服', 1000, 500, '2009-09-20')
insert into Product values('0002', '打孔器', '办公用品', 500, 320, '2009-09-11')
insert into Product values('0003', '运动T恤', '衣服', 4000, 2800, NULL)
insert into Product values('0004', '菜刀', '厨房用品', 3000, 2800, '2009-09-20')
insert into Product values('0005', '高压锅', '厨房用品', 6800, 5000, '2009-01-15')
insert into Product values('0006', '叉子', '厨房用品', 500, NULL, '2009-09-20')
insert into Product values('0007', '擦菜板', '厨房用品', 880, 790, '2008-04-28')
insert into Product values('0008', '圆珠笔', '办公用品', 100, NULL, '2009-11-11')