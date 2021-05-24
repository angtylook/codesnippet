(()=>{
	function getArr(value:number, count:number) : number[] {
		const arr : number[] = []
		for(let i = 0 ; i < count; i++) {
			arr.push(value)
		}
		return arr
	}
	console.log(getArr(1,3))

	function getArr1(value:any, count:number) : any[] {
		const arr : any[] = []
		for(let i = 0 ; i < count; i++) {
			arr.push(value)
		}
		return arr
	}
	console.log(getArr1("aa",3))

	// 泛型函数
	function getArrGen<T>(value: T, count: number): T[] {
		const arr : Array<T> = []
		for(let i = 0 ; i < count; i++) {
			arr.push(value)
		}
		return arr
	}
	console.log(getArrGen<number>(101, 8))
	console.log(getArrGen<string>("hcl", 8))

	function getPair<K,V>(k: K, v: V): [K,V] {
		return [k,v]
	}

	const pair = getPair<string, number>("count", 100)
	console.log(pair)

	// 泛型类

	
})()

