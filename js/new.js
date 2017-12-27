/*
 * 这是一张 JavaScript 代码草稿纸。
 *
 * 输入一些 JavaScript，然后可点击右键或从“执行”菜单中选择：
 * 1. 运行 对选中的文本求值(eval) (Ctrl+R)；
 * 2. 查看 对返回值使用对象查看器 (Ctrl+I)；
 * 3. 显示 在选中内容后面以注释的形式插入返回的结果。 (Ctrl+L)
 */

var Vehicle = function () {
  this.price = 1000;
};

var v = new Vehicle();
console.log(v.price)

function Animal(name) {
  this.name = name;
}

Animal.prototype.color = 'white'

var cat1 = new Animal('Cat 1');
var cat2 = new Animal('Cat 2');

console.log(cat1.color, cat2.color);

