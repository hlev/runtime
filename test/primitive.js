/* test rig */ var t = 1, tmax = 3
function ok (a, d) { console.log(a ? 'ok ' + (t++) + ' -' : 'not ok ' + (t++) + ' -', d); }
console.log(t + '..' + tmax);
ok(process.versions.colony, 'running in colony')

ok(null < 400, 'null < positive');
ok(!(5 < null), 'positive < null');
ok(null > -400, 'null > negative');
ok(!(null > 0), 'null not > 0');
ok(!(null < 0), 'null not < 0');
ok(null != 0, 'null != 0');
ok(!(null < null), 'null < null')
ok(!(null > null), 'null > null')
ok(null == null, 'null == null')

ok(undefined < 400, 'undefined < positive #TODO');
ok(undefined > -400, 'undefined > positive #TODO');

ok(!(0) == true, '0 is falsy');
ok(!(false) == true, 'false is falsy');
ok(!('') == true, '"" is falsy');

var b = [1, 2, 3];
var a = {b: b};

ok(a instanceof Object);
ok(!(a instanceof Array));
ok(!(a instanceof Function))
ok(b instanceof Object)
ok(b instanceof Array);
ok(!(b instanceof Function))
ok(parseFloat instanceof Object)
ok(!(parseFloat instanceof Array))
ok(parseFloat instanceof Function)