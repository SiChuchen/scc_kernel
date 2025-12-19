
scc_kernel:     file format elf32-i386


Disassembly of section .text:

00100000 <gdt_flush>:
  100000:	8b 44 24 04          	mov    eax,DWORD PTR [esp+0x4]
  100004:	0f 01 10             	lgdtd  [eax]
  100007:	66 b8 10 00          	mov    ax,0x10
  10000b:	8e d8                	mov    ds,eax
  10000d:	8e c0                	mov    es,eax
  10000f:	8e e0                	mov    fs,eax
  100011:	8e e8                	mov    gs,eax
  100013:	8e d0                	mov    ss,eax
  100015:	ea 1c 00 10 00 08 00 	jmp    0x8:0x10001c

0010001c <gdt_flush.flush>:
  10001c:	c3                   	ret    
  10001d:	66 90                	xchg   ax,ax
  10001f:	90                   	nop
  100020:	02 b0 ad 1b 03 00    	add    dh,BYTE PTR [eax+0x31bad]
  100026:	00 00                	add    BYTE PTR [eax],al
  100028:	fb                   	sti    
  100029:	4f                   	dec    edi
  10002a:	52                   	push   edx
  10002b:	e4                   	.byte 0xe4

0010002c <start>:
  10002c:	fa                   	cli    
  10002d:	bc 03 80 00 00       	mov    esp,0x8003
  100032:	bd 00 00 00 00       	mov    ebp,0x0
  100037:	83 e4 f0             	and    esp,0xfffffff0
  10003a:	89 1d 20 c0 10 00    	mov    DWORD PTR ds:0x10c020,ebx
  100040:	e8 bc 19 00 00       	call   101a01 <kern_entry>

00100045 <stop>:
  100045:	f4                   	hlt    
  100046:	eb fd                	jmp    100045 <stop>
  100048:	66 90                	xchg   ax,ax
  10004a:	66 90                	xchg   ax,ax
  10004c:	66 90                	xchg   ax,ax
  10004e:	66 90                	xchg   ax,ax

00100050 <idt_flush>:
  100050:	8b 44 24 04          	mov    eax,DWORD PTR [esp+0x4]
  100054:	0f 01 18             	lidtd  [eax]
  100057:	c3                   	ret    

00100058 <isr0>:
  100058:	fa                   	cli    
  100059:	6a 00                	push   0x0
  10005b:	6a 00                	push   0x0
  10005d:	e9 fc 00 00 00       	jmp    10015e <isr_common_stub>

00100062 <isr1>:
  100062:	fa                   	cli    
  100063:	6a 00                	push   0x0
  100065:	6a 01                	push   0x1
  100067:	e9 f2 00 00 00       	jmp    10015e <isr_common_stub>

0010006c <isr2>:
  10006c:	fa                   	cli    
  10006d:	6a 00                	push   0x0
  10006f:	6a 02                	push   0x2
  100071:	e9 e8 00 00 00       	jmp    10015e <isr_common_stub>

00100076 <isr3>:
  100076:	fa                   	cli    
  100077:	6a 00                	push   0x0
  100079:	6a 03                	push   0x3
  10007b:	e9 de 00 00 00       	jmp    10015e <isr_common_stub>

00100080 <isr4>:
  100080:	fa                   	cli    
  100081:	6a 00                	push   0x0
  100083:	6a 04                	push   0x4
  100085:	e9 d4 00 00 00       	jmp    10015e <isr_common_stub>

0010008a <isr5>:
  10008a:	fa                   	cli    
  10008b:	6a 00                	push   0x0
  10008d:	6a 05                	push   0x5
  10008f:	e9 ca 00 00 00       	jmp    10015e <isr_common_stub>

00100094 <isr6>:
  100094:	fa                   	cli    
  100095:	6a 00                	push   0x0
  100097:	6a 06                	push   0x6
  100099:	e9 c0 00 00 00       	jmp    10015e <isr_common_stub>

0010009e <isr7>:
  10009e:	fa                   	cli    
  10009f:	6a 00                	push   0x0
  1000a1:	6a 07                	push   0x7
  1000a3:	e9 b6 00 00 00       	jmp    10015e <isr_common_stub>

001000a8 <isr8>:
  1000a8:	fa                   	cli    
  1000a9:	6a 08                	push   0x8
  1000ab:	e9 ae 00 00 00       	jmp    10015e <isr_common_stub>

001000b0 <isr9>:
  1000b0:	fa                   	cli    
  1000b1:	6a 00                	push   0x0
  1000b3:	6a 09                	push   0x9
  1000b5:	e9 a4 00 00 00       	jmp    10015e <isr_common_stub>

001000ba <isr10>:
  1000ba:	fa                   	cli    
  1000bb:	6a 0a                	push   0xa
  1000bd:	e9 9c 00 00 00       	jmp    10015e <isr_common_stub>

001000c2 <isr11>:
  1000c2:	fa                   	cli    
  1000c3:	6a 0b                	push   0xb
  1000c5:	e9 94 00 00 00       	jmp    10015e <isr_common_stub>

001000ca <isr12>:
  1000ca:	fa                   	cli    
  1000cb:	6a 0c                	push   0xc
  1000cd:	e9 8c 00 00 00       	jmp    10015e <isr_common_stub>

001000d2 <isr13>:
  1000d2:	fa                   	cli    
  1000d3:	6a 0d                	push   0xd
  1000d5:	e9 84 00 00 00       	jmp    10015e <isr_common_stub>

001000da <isr14>:
  1000da:	fa                   	cli    
  1000db:	6a 0e                	push   0xe
  1000dd:	eb 7f                	jmp    10015e <isr_common_stub>

001000df <isr15>:
  1000df:	fa                   	cli    
  1000e0:	6a 00                	push   0x0
  1000e2:	6a 0f                	push   0xf
  1000e4:	eb 78                	jmp    10015e <isr_common_stub>

001000e6 <isr16>:
  1000e6:	fa                   	cli    
  1000e7:	6a 00                	push   0x0
  1000e9:	6a 10                	push   0x10
  1000eb:	eb 71                	jmp    10015e <isr_common_stub>

001000ed <isr17>:
  1000ed:	fa                   	cli    
  1000ee:	6a 11                	push   0x11
  1000f0:	eb 6c                	jmp    10015e <isr_common_stub>

001000f2 <isr18>:
  1000f2:	fa                   	cli    
  1000f3:	6a 00                	push   0x0
  1000f5:	6a 12                	push   0x12
  1000f7:	eb 65                	jmp    10015e <isr_common_stub>

001000f9 <isr19>:
  1000f9:	fa                   	cli    
  1000fa:	6a 00                	push   0x0
  1000fc:	6a 13                	push   0x13
  1000fe:	eb 5e                	jmp    10015e <isr_common_stub>

00100100 <isr20>:
  100100:	fa                   	cli    
  100101:	6a 00                	push   0x0
  100103:	6a 14                	push   0x14
  100105:	eb 57                	jmp    10015e <isr_common_stub>

00100107 <isr21>:
  100107:	fa                   	cli    
  100108:	6a 00                	push   0x0
  10010a:	6a 15                	push   0x15
  10010c:	eb 50                	jmp    10015e <isr_common_stub>

0010010e <isr22>:
  10010e:	fa                   	cli    
  10010f:	6a 00                	push   0x0
  100111:	6a 16                	push   0x16
  100113:	eb 49                	jmp    10015e <isr_common_stub>

00100115 <isr23>:
  100115:	fa                   	cli    
  100116:	6a 00                	push   0x0
  100118:	6a 17                	push   0x17
  10011a:	eb 42                	jmp    10015e <isr_common_stub>

0010011c <isr24>:
  10011c:	fa                   	cli    
  10011d:	6a 00                	push   0x0
  10011f:	6a 18                	push   0x18
  100121:	eb 3b                	jmp    10015e <isr_common_stub>

00100123 <isr25>:
  100123:	fa                   	cli    
  100124:	6a 00                	push   0x0
  100126:	6a 19                	push   0x19
  100128:	eb 34                	jmp    10015e <isr_common_stub>

0010012a <isr26>:
  10012a:	fa                   	cli    
  10012b:	6a 00                	push   0x0
  10012d:	6a 1a                	push   0x1a
  10012f:	eb 2d                	jmp    10015e <isr_common_stub>

00100131 <isr27>:
  100131:	fa                   	cli    
  100132:	6a 00                	push   0x0
  100134:	6a 1b                	push   0x1b
  100136:	eb 26                	jmp    10015e <isr_common_stub>

00100138 <isr28>:
  100138:	fa                   	cli    
  100139:	6a 00                	push   0x0
  10013b:	6a 1c                	push   0x1c
  10013d:	eb 1f                	jmp    10015e <isr_common_stub>

0010013f <isr29>:
  10013f:	fa                   	cli    
  100140:	6a 00                	push   0x0
  100142:	6a 1d                	push   0x1d
  100144:	eb 18                	jmp    10015e <isr_common_stub>

00100146 <isr30>:
  100146:	fa                   	cli    
  100147:	6a 00                	push   0x0
  100149:	6a 1e                	push   0x1e
  10014b:	eb 11                	jmp    10015e <isr_common_stub>

0010014d <isr31>:
  10014d:	fa                   	cli    
  10014e:	6a 00                	push   0x0
  100150:	6a 1f                	push   0x1f
  100152:	eb 0a                	jmp    10015e <isr_common_stub>

00100154 <isr255>:
  100154:	fa                   	cli    
  100155:	6a 00                	push   0x0
  100157:	68 ff 00 00 00       	push   0xff
  10015c:	eb 00                	jmp    10015e <isr_common_stub>

0010015e <isr_common_stub>:
  10015e:	60                   	pusha  
  10015f:	66 8c d8             	mov    ax,ds
  100162:	50                   	push   eax
  100163:	66 b8 10 00          	mov    ax,0x10
  100167:	8e d8                	mov    ds,eax
  100169:	8e c0                	mov    es,eax
  10016b:	8e e0                	mov    fs,eax
  10016d:	8e e8                	mov    gs,eax
  10016f:	8e d0                	mov    ss,eax
  100171:	54                   	push   esp
  100172:	e8 83 12 00 00       	call   1013fa <isr_handler>
  100177:	83 c4 04             	add    esp,0x4
  10017a:	5b                   	pop    ebx
  10017b:	8e db                	mov    ds,ebx
  10017d:	8e c3                	mov    es,ebx
  10017f:	8e e3                	mov    fs,ebx
  100181:	8e eb                	mov    gs,ebx
  100183:	8e d3                	mov    ss,ebx
  100185:	61                   	popa   
  100186:	83 c4 08             	add    esp,0x8
  100189:	cf                   	iret   

0010018a <irq0>:
  10018a:	fa                   	cli    
  10018b:	6a 00                	push   0x0
  10018d:	6a 20                	push   0x20
  10018f:	eb 69                	jmp    1001fa <irq_common_stub>

00100191 <irq1>:
  100191:	fa                   	cli    
  100192:	6a 00                	push   0x0
  100194:	6a 21                	push   0x21
  100196:	eb 62                	jmp    1001fa <irq_common_stub>

00100198 <irq2>:
  100198:	fa                   	cli    
  100199:	6a 00                	push   0x0
  10019b:	6a 22                	push   0x22
  10019d:	eb 5b                	jmp    1001fa <irq_common_stub>

0010019f <irq3>:
  10019f:	fa                   	cli    
  1001a0:	6a 00                	push   0x0
  1001a2:	6a 23                	push   0x23
  1001a4:	eb 54                	jmp    1001fa <irq_common_stub>

001001a6 <irq4>:
  1001a6:	fa                   	cli    
  1001a7:	6a 00                	push   0x0
  1001a9:	6a 24                	push   0x24
  1001ab:	eb 4d                	jmp    1001fa <irq_common_stub>

001001ad <irq5>:
  1001ad:	fa                   	cli    
  1001ae:	6a 00                	push   0x0
  1001b0:	6a 25                	push   0x25
  1001b2:	eb 46                	jmp    1001fa <irq_common_stub>

001001b4 <irq6>:
  1001b4:	fa                   	cli    
  1001b5:	6a 00                	push   0x0
  1001b7:	6a 26                	push   0x26
  1001b9:	eb 3f                	jmp    1001fa <irq_common_stub>

001001bb <irq7>:
  1001bb:	fa                   	cli    
  1001bc:	6a 00                	push   0x0
  1001be:	6a 27                	push   0x27
  1001c0:	eb 38                	jmp    1001fa <irq_common_stub>

001001c2 <irq8>:
  1001c2:	fa                   	cli    
  1001c3:	6a 00                	push   0x0
  1001c5:	6a 28                	push   0x28
  1001c7:	eb 31                	jmp    1001fa <irq_common_stub>

001001c9 <irq9>:
  1001c9:	fa                   	cli    
  1001ca:	6a 00                	push   0x0
  1001cc:	6a 29                	push   0x29
  1001ce:	eb 2a                	jmp    1001fa <irq_common_stub>

001001d0 <irq10>:
  1001d0:	fa                   	cli    
  1001d1:	6a 00                	push   0x0
  1001d3:	6a 2a                	push   0x2a
  1001d5:	eb 23                	jmp    1001fa <irq_common_stub>

001001d7 <irq11>:
  1001d7:	fa                   	cli    
  1001d8:	6a 00                	push   0x0
  1001da:	6a 2b                	push   0x2b
  1001dc:	eb 1c                	jmp    1001fa <irq_common_stub>

001001de <irq12>:
  1001de:	fa                   	cli    
  1001df:	6a 00                	push   0x0
  1001e1:	6a 2c                	push   0x2c
  1001e3:	eb 15                	jmp    1001fa <irq_common_stub>

001001e5 <irq13>:
  1001e5:	fa                   	cli    
  1001e6:	6a 00                	push   0x0
  1001e8:	6a 2d                	push   0x2d
  1001ea:	eb 0e                	jmp    1001fa <irq_common_stub>

001001ec <irq14>:
  1001ec:	fa                   	cli    
  1001ed:	6a 00                	push   0x0
  1001ef:	6a 2e                	push   0x2e
  1001f1:	eb 07                	jmp    1001fa <irq_common_stub>

001001f3 <irq15>:
  1001f3:	fa                   	cli    
  1001f4:	6a 00                	push   0x0
  1001f6:	6a 2f                	push   0x2f
  1001f8:	eb 00                	jmp    1001fa <irq_common_stub>

001001fa <irq_common_stub>:
  1001fa:	60                   	pusha  
  1001fb:	66 8c d8             	mov    ax,ds
  1001fe:	50                   	push   eax
  1001ff:	66 b8 10 00          	mov    ax,0x10
  100203:	8e d8                	mov    ds,eax
  100205:	8e c0                	mov    es,eax
  100207:	8e e0                	mov    fs,eax
  100209:	8e e8                	mov    gs,eax
  10020b:	8e d0                	mov    ss,eax
  10020d:	54                   	push   esp
  10020e:	e8 7a 12 00 00       	call   10148d <irq_handler>
  100213:	83 c4 04             	add    esp,0x4
  100216:	5b                   	pop    ebx
  100217:	8e db                	mov    ds,ebx
  100219:	8e c3                	mov    es,ebx
  10021b:	8e e3                	mov    fs,ebx
  10021d:	8e eb                	mov    gs,ebx
  10021f:	8e d3                	mov    ss,ebx
  100221:	61                   	popa   
  100222:	83 c4 08             	add    esp,0x8
  100225:	cf                   	iret   

00100226 <init_gdt>:
  100226:	f3 0f 1e fb          	endbr32 
  10022a:	55                   	push   ebp
  10022b:	89 e5                	mov    ebp,esp
  10022d:	53                   	push   ebx
  10022e:	83 ec 04             	sub    esp,0x4
  100231:	e8 ce 2d 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  100236:	81 c3 ca 3d 00 00    	add    ebx,0x3dca
  10023c:	c7 c0 28 d0 18 00    	mov    eax,0x18d028
  100242:	66 c7 00 27 00       	mov    WORD PTR [eax],0x27
  100247:	c7 c0 00 d0 18 00    	mov    eax,0x18d000
  10024d:	89 c2                	mov    edx,eax
  10024f:	c7 c0 28 d0 18 00    	mov    eax,0x18d028
  100255:	89 50 02             	mov    DWORD PTR [eax+0x2],edx
  100258:	83 ec 0c             	sub    esp,0xc
  10025b:	6a 00                	push   0x0
  10025d:	6a 00                	push   0x0
  10025f:	6a 00                	push   0x0
  100261:	6a 00                	push   0x0
  100263:	6a 00                	push   0x0
  100265:	e8 87 00 00 00       	call   1002f1 <gdt_set_gate>
  10026a:	83 c4 20             	add    esp,0x20
  10026d:	83 ec 0c             	sub    esp,0xc
  100270:	68 cf 00 00 00       	push   0xcf
  100275:	68 9a 00 00 00       	push   0x9a
  10027a:	6a ff                	push   0xffffffff
  10027c:	6a 00                	push   0x0
  10027e:	6a 01                	push   0x1
  100280:	e8 6c 00 00 00       	call   1002f1 <gdt_set_gate>
  100285:	83 c4 20             	add    esp,0x20
  100288:	83 ec 0c             	sub    esp,0xc
  10028b:	68 cf 00 00 00       	push   0xcf
  100290:	68 92 00 00 00       	push   0x92
  100295:	6a ff                	push   0xffffffff
  100297:	6a 00                	push   0x0
  100299:	6a 02                	push   0x2
  10029b:	e8 51 00 00 00       	call   1002f1 <gdt_set_gate>
  1002a0:	83 c4 20             	add    esp,0x20
  1002a3:	83 ec 0c             	sub    esp,0xc
  1002a6:	68 cf 00 00 00       	push   0xcf
  1002ab:	68 fa 00 00 00       	push   0xfa
  1002b0:	6a ff                	push   0xffffffff
  1002b2:	6a 00                	push   0x0
  1002b4:	6a 03                	push   0x3
  1002b6:	e8 36 00 00 00       	call   1002f1 <gdt_set_gate>
  1002bb:	83 c4 20             	add    esp,0x20
  1002be:	83 ec 0c             	sub    esp,0xc
  1002c1:	68 cf 00 00 00       	push   0xcf
  1002c6:	68 f2 00 00 00       	push   0xf2
  1002cb:	6a ff                	push   0xffffffff
  1002cd:	6a 00                	push   0x0
  1002cf:	6a 04                	push   0x4
  1002d1:	e8 1b 00 00 00       	call   1002f1 <gdt_set_gate>
  1002d6:	83 c4 20             	add    esp,0x20
  1002d9:	c7 c0 28 d0 18 00    	mov    eax,0x18d028
  1002df:	83 ec 0c             	sub    esp,0xc
  1002e2:	50                   	push   eax
  1002e3:	e8 18 fd ff ff       	call   100000 <gdt_flush>
  1002e8:	83 c4 10             	add    esp,0x10
  1002eb:	90                   	nop
  1002ec:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  1002ef:	c9                   	leave  
  1002f0:	c3                   	ret    

001002f1 <gdt_set_gate>:
  1002f1:	f3 0f 1e fb          	endbr32 
  1002f5:	55                   	push   ebp
  1002f6:	89 e5                	mov    ebp,esp
  1002f8:	53                   	push   ebx
  1002f9:	83 ec 08             	sub    esp,0x8
  1002fc:	e8 ff 2c 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  100301:	05 ff 3c 00 00       	add    eax,0x3cff
  100306:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  100309:	8b 55 18             	mov    edx,DWORD PTR [ebp+0x18]
  10030c:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  10030f:	88 55 f4             	mov    BYTE PTR [ebp-0xc],dl
  100312:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  100315:	89 d3                	mov    ebx,edx
  100317:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  10031d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  100320:	66 89 5c ca 02       	mov    WORD PTR [edx+ecx*8+0x2],bx
  100325:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  100328:	c1 ea 10             	shr    edx,0x10
  10032b:	89 d3                	mov    ebx,edx
  10032d:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  100333:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  100336:	88 5c ca 04          	mov    BYTE PTR [edx+ecx*8+0x4],bl
  10033a:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  10033d:	c1 ea 18             	shr    edx,0x18
  100340:	89 d3                	mov    ebx,edx
  100342:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  100348:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  10034b:	88 5c ca 07          	mov    BYTE PTR [edx+ecx*8+0x7],bl
  10034f:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  100352:	89 d3                	mov    ebx,edx
  100354:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  10035a:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  10035d:	66 89 1c ca          	mov    WORD PTR [edx+ecx*8],bx
  100361:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  100364:	c1 ea 10             	shr    edx,0x10
  100367:	89 d3                	mov    ebx,edx
  100369:	83 e3 0f             	and    ebx,0xf
  10036c:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  100372:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  100375:	88 5c ca 06          	mov    BYTE PTR [edx+ecx*8+0x6],bl
  100379:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  10037f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  100382:	0f b6 54 ca 06       	movzx  edx,BYTE PTR [edx+ecx*8+0x6]
  100387:	89 d1                	mov    ecx,edx
  100389:	0f b6 55 f4          	movzx  edx,BYTE PTR [ebp-0xc]
  10038d:	83 e2 f0             	and    edx,0xfffffff0
  100390:	09 ca                	or     edx,ecx
  100392:	89 d3                	mov    ebx,edx
  100394:	c7 c2 00 d0 18 00    	mov    edx,0x18d000
  10039a:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  10039d:	88 5c ca 06          	mov    BYTE PTR [edx+ecx*8+0x6],bl
  1003a1:	c7 c0 00 d0 18 00    	mov    eax,0x18d000
  1003a7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  1003aa:	0f b6 4d f8          	movzx  ecx,BYTE PTR [ebp-0x8]
  1003ae:	88 4c d0 05          	mov    BYTE PTR [eax+edx*8+0x5],cl
  1003b2:	90                   	nop
  1003b3:	83 c4 08             	add    esp,0x8
  1003b6:	5b                   	pop    ebx
  1003b7:	5d                   	pop    ebp
  1003b8:	c3                   	ret    

001003b9 <init_debug>:
  1003b9:	f3 0f 1e fb          	endbr32 
  1003bd:	55                   	push   ebp
  1003be:	89 e5                	mov    ebp,esp
  1003c0:	53                   	push   ebx
  1003c1:	83 ec 14             	sub    esp,0x14
  1003c4:	e8 3b 2c 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  1003c9:	81 c3 37 3c 00 00    	add    ebx,0x3c37
  1003cf:	c7 c0 20 c0 10 00    	mov    eax,0x10c020
  1003d5:	8b 10                	mov    edx,DWORD PTR [eax]
  1003d7:	8d 45 e8             	lea    eax,[ebp-0x18]
  1003da:	83 ec 08             	sub    esp,0x8
  1003dd:	52                   	push   edx
  1003de:	50                   	push   eax
  1003df:	e8 b1 13 00 00       	call   101795 <elf_from_multiboot>
  1003e4:	83 c4 0c             	add    esp,0xc
  1003e7:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  1003ea:	89 83 24 80 00 00    	mov    DWORD PTR [ebx+0x8024],eax
  1003f0:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  1003f3:	89 83 28 80 00 00    	mov    DWORD PTR [ebx+0x8028],eax
  1003f9:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  1003fc:	89 83 2c 80 00 00    	mov    DWORD PTR [ebx+0x802c],eax
  100402:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100405:	89 83 30 80 00 00    	mov    DWORD PTR [ebx+0x8030],eax
  10040b:	90                   	nop
  10040c:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  10040f:	c9                   	leave  
  100410:	c3                   	ret    

00100411 <print_cur_status>:
  100411:	f3 0f 1e fb          	endbr32 
  100415:	55                   	push   ebp
  100416:	89 e5                	mov    ebp,esp
  100418:	53                   	push   ebx
  100419:	83 ec 14             	sub    esp,0x14
  10041c:	e8 e3 2b 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  100421:	81 c3 df 3b 00 00    	add    ebx,0x3bdf
  100427:	8c 4d f6             	mov    WORD PTR [ebp-0xa],cs
  10042a:	8c 5d f4             	mov    WORD PTR [ebp-0xc],ds
  10042d:	8c 45 f2             	mov    WORD PTR [ebp-0xe],es
  100430:	8c 55 f0             	mov    WORD PTR [ebp-0x10],ss
  100433:	0f b7 45 f6          	movzx  eax,WORD PTR [ebp-0xa]
  100437:	0f b7 c0             	movzx  eax,ax
  10043a:	83 e0 03             	and    eax,0x3
  10043d:	89 c2                	mov    edx,eax
  10043f:	8b 83 34 80 00 00    	mov    eax,DWORD PTR [ebx+0x8034]
  100445:	83 ec 04             	sub    esp,0x4
  100448:	52                   	push   edx
  100449:	50                   	push   eax
  10044a:	8d 83 0c f0 ff ff    	lea    eax,[ebx-0xff4]
  100450:	50                   	push   eax
  100451:	e8 a6 01 00 00       	call   1005fc <printk>
  100456:	83 c4 10             	add    esp,0x10
  100459:	0f b7 45 f6          	movzx  eax,WORD PTR [ebp-0xa]
  10045d:	0f b7 d0             	movzx  edx,ax
  100460:	8b 83 34 80 00 00    	mov    eax,DWORD PTR [ebx+0x8034]
  100466:	83 ec 04             	sub    esp,0x4
  100469:	52                   	push   edx
  10046a:	50                   	push   eax
  10046b:	8d 83 1a f0 ff ff    	lea    eax,[ebx-0xfe6]
  100471:	50                   	push   eax
  100472:	e8 85 01 00 00       	call   1005fc <printk>
  100477:	83 c4 10             	add    esp,0x10
  10047a:	0f b7 45 f4          	movzx  eax,WORD PTR [ebp-0xc]
  10047e:	0f b7 d0             	movzx  edx,ax
  100481:	8b 83 34 80 00 00    	mov    eax,DWORD PTR [ebx+0x8034]
  100487:	83 ec 04             	sub    esp,0x4
  10048a:	52                   	push   edx
  10048b:	50                   	push   eax
  10048c:	8d 83 28 f0 ff ff    	lea    eax,[ebx-0xfd8]
  100492:	50                   	push   eax
  100493:	e8 64 01 00 00       	call   1005fc <printk>
  100498:	83 c4 10             	add    esp,0x10
  10049b:	0f b7 45 f2          	movzx  eax,WORD PTR [ebp-0xe]
  10049f:	0f b7 d0             	movzx  edx,ax
  1004a2:	8b 83 34 80 00 00    	mov    eax,DWORD PTR [ebx+0x8034]
  1004a8:	83 ec 04             	sub    esp,0x4
  1004ab:	52                   	push   edx
  1004ac:	50                   	push   eax
  1004ad:	8d 83 36 f0 ff ff    	lea    eax,[ebx-0xfca]
  1004b3:	50                   	push   eax
  1004b4:	e8 43 01 00 00       	call   1005fc <printk>
  1004b9:	83 c4 10             	add    esp,0x10
  1004bc:	0f b7 45 f0          	movzx  eax,WORD PTR [ebp-0x10]
  1004c0:	0f b7 d0             	movzx  edx,ax
  1004c3:	8b 83 34 80 00 00    	mov    eax,DWORD PTR [ebx+0x8034]
  1004c9:	83 ec 04             	sub    esp,0x4
  1004cc:	52                   	push   edx
  1004cd:	50                   	push   eax
  1004ce:	8d 83 44 f0 ff ff    	lea    eax,[ebx-0xfbc]
  1004d4:	50                   	push   eax
  1004d5:	e8 22 01 00 00       	call   1005fc <printk>
  1004da:	83 c4 10             	add    esp,0x10
  1004dd:	8b 83 34 80 00 00    	mov    eax,DWORD PTR [ebx+0x8034]
  1004e3:	83 c0 01             	add    eax,0x1
  1004e6:	89 83 34 80 00 00    	mov    DWORD PTR [ebx+0x8034],eax
  1004ec:	90                   	nop
  1004ed:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  1004f0:	c9                   	leave  
  1004f1:	c3                   	ret    

001004f2 <panic>:
  1004f2:	f3 0f 1e fb          	endbr32 
  1004f6:	55                   	push   ebp
  1004f7:	89 e5                	mov    ebp,esp
  1004f9:	53                   	push   ebx
  1004fa:	83 ec 04             	sub    esp,0x4
  1004fd:	e8 02 2b 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  100502:	81 c3 fe 3a 00 00    	add    ebx,0x3afe
  100508:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  10050b:	8d 83 52 f0 ff ff    	lea    eax,[ebx-0xfae]
  100511:	50                   	push   eax
  100512:	6a 02                	push   0x2
  100514:	6a 00                	push   0x0
  100516:	e8 3f 01 00 00       	call   10065a <printk_color>
  10051b:	83 c4 10             	add    esp,0x10
  10051e:	83 ec 08             	sub    esp,0x8
  100521:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  100524:	8d 83 55 f0 ff ff    	lea    eax,[ebx-0xfab]
  10052a:	50                   	push   eax
  10052b:	e8 cc 00 00 00       	call   1005fc <printk>
  100530:	83 c4 10             	add    esp,0x10
  100533:	e8 2a 00 00 00       	call   100562 <print_stack_trace>
  100538:	83 ec 0c             	sub    esp,0xc
  10053b:	8d 83 6b f0 ff ff    	lea    eax,[ebx-0xf95]
  100541:	50                   	push   eax
  100542:	e8 b5 00 00 00       	call   1005fc <printk>
  100547:	83 c4 10             	add    esp,0x10
  10054a:	83 ec 04             	sub    esp,0x4
  10054d:	8d 83 70 f0 ff ff    	lea    eax,[ebx-0xf90]
  100553:	50                   	push   eax
  100554:	6a 02                	push   0x2
  100556:	6a 00                	push   0x0
  100558:	e8 fd 00 00 00       	call   10065a <printk_color>
  10055d:	83 c4 10             	add    esp,0x10
  100560:	eb fe                	jmp    100560 <panic+0x6e>

00100562 <print_stack_trace>:
  100562:	f3 0f 1e fb          	endbr32 
  100566:	55                   	push   ebp
  100567:	89 e5                	mov    ebp,esp
  100569:	53                   	push   ebx
  10056a:	83 ec 14             	sub    esp,0x14
  10056d:	e8 92 2a 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  100572:	81 c3 8e 3a 00 00    	add    ebx,0x3a8e
  100578:	89 e8                	mov    eax,ebp
  10057a:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  10057d:	eb 42                	jmp    1005c1 <print_stack_trace+0x5f>
  10057f:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100582:	83 c0 04             	add    eax,0x4
  100585:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100588:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  10058b:	8b 00                	mov    eax,DWORD PTR [eax]
  10058d:	83 ec 08             	sub    esp,0x8
  100590:	8d 93 24 80 00 00    	lea    edx,[ebx+0x8024]
  100596:	52                   	push   edx
  100597:	50                   	push   eax
  100598:	e8 2b 13 00 00       	call   1018c8 <elf_lookup_symbol>
  10059d:	83 c4 10             	add    esp,0x10
  1005a0:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  1005a3:	8b 12                	mov    edx,DWORD PTR [edx]
  1005a5:	83 ec 04             	sub    esp,0x4
  1005a8:	50                   	push   eax
  1005a9:	52                   	push   edx
  1005aa:	8d 83 7e f0 ff ff    	lea    eax,[ebx-0xf82]
  1005b0:	50                   	push   eax
  1005b1:	e8 46 00 00 00       	call   1005fc <printk>
  1005b6:	83 c4 10             	add    esp,0x10
  1005b9:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  1005bc:	8b 00                	mov    eax,DWORD PTR [eax]
  1005be:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  1005c1:	83 7d f4 00          	cmp    DWORD PTR [ebp-0xc],0x0
  1005c5:	75 b8                	jne    10057f <print_stack_trace+0x1d>
  1005c7:	90                   	nop
  1005c8:	90                   	nop
  1005c9:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  1005cc:	c9                   	leave  
  1005cd:	c3                   	ret    

001005ce <strlen>:
  1005ce:	55                   	push   ebp
  1005cf:	89 e5                	mov    ebp,esp
  1005d1:	83 ec 10             	sub    esp,0x10
  1005d4:	e8 27 2a 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  1005d9:	05 27 3a 00 00       	add    eax,0x3a27
  1005de:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1005e1:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  1005e4:	eb 04                	jmp    1005ea <strlen+0x1c>
  1005e6:	83 45 fc 01          	add    DWORD PTR [ebp-0x4],0x1
  1005ea:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  1005ed:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  1005f0:	84 c0                	test   al,al
  1005f2:	75 f2                	jne    1005e6 <strlen+0x18>
  1005f4:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  1005f7:	2b 45 08             	sub    eax,DWORD PTR [ebp+0x8]
  1005fa:	c9                   	leave  
  1005fb:	c3                   	ret    

001005fc <printk>:
  1005fc:	f3 0f 1e fb          	endbr32 
  100600:	55                   	push   ebp
  100601:	89 e5                	mov    ebp,esp
  100603:	53                   	push   ebx
  100604:	83 ec 14             	sub    esp,0x14
  100607:	e8 f8 29 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  10060c:	81 c3 f4 39 00 00    	add    ebx,0x39f4
  100612:	8d 45 0c             	lea    eax,[ebp+0xc]
  100615:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100618:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  10061b:	83 ec 04             	sub    esp,0x4
  10061e:	50                   	push   eax
  10061f:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  100622:	8d 83 40 80 00 00    	lea    eax,[ebx+0x8040]
  100628:	50                   	push   eax
  100629:	e8 2f 03 00 00       	call   10095d <vsprintf>
  10062e:	83 c4 10             	add    esp,0x10
  100631:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  100634:	8d 93 40 80 00 00    	lea    edx,[ebx+0x8040]
  10063a:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10063d:	01 d0                	add    eax,edx
  10063f:	c6 00 00             	mov    BYTE PTR [eax],0x0
  100642:	83 ec 0c             	sub    esp,0xc
  100645:	8d 83 40 80 00 00    	lea    eax,[ebx+0x8040]
  10064b:	50                   	push   eax
  10064c:	e8 d4 18 00 00       	call   101f25 <console_write>
  100651:	83 c4 10             	add    esp,0x10
  100654:	90                   	nop
  100655:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  100658:	c9                   	leave  
  100659:	c3                   	ret    

0010065a <printk_color>:
  10065a:	f3 0f 1e fb          	endbr32 
  10065e:	55                   	push   ebp
  10065f:	89 e5                	mov    ebp,esp
  100661:	53                   	push   ebx
  100662:	83 ec 14             	sub    esp,0x14
  100665:	e8 9a 29 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  10066a:	81 c3 96 39 00 00    	add    ebx,0x3996
  100670:	8d 45 14             	lea    eax,[ebp+0x14]
  100673:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100676:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100679:	83 ec 04             	sub    esp,0x4
  10067c:	50                   	push   eax
  10067d:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  100680:	8d 83 40 84 00 00    	lea    eax,[ebx+0x8440]
  100686:	50                   	push   eax
  100687:	e8 d1 02 00 00       	call   10095d <vsprintf>
  10068c:	83 c4 10             	add    esp,0x10
  10068f:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  100692:	8d 93 40 84 00 00    	lea    edx,[ebx+0x8440]
  100698:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10069b:	01 d0                	add    eax,edx
  10069d:	c6 00 00             	mov    BYTE PTR [eax],0x0
  1006a0:	83 ec 04             	sub    esp,0x4
  1006a3:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  1006a6:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  1006a9:	8d 83 40 84 00 00    	lea    eax,[ebx+0x8440]
  1006af:	50                   	push   eax
  1006b0:	e8 b3 18 00 00       	call   101f68 <console_write_color>
  1006b5:	83 c4 10             	add    esp,0x10
  1006b8:	90                   	nop
  1006b9:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  1006bc:	c9                   	leave  
  1006bd:	c3                   	ret    

001006be <skip_atoi>:
  1006be:	f3 0f 1e fb          	endbr32 
  1006c2:	55                   	push   ebp
  1006c3:	89 e5                	mov    ebp,esp
  1006c5:	53                   	push   ebx
  1006c6:	83 ec 10             	sub    esp,0x10
  1006c9:	e8 32 29 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  1006ce:	05 32 39 00 00       	add    eax,0x3932
  1006d3:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [ebp-0x8],0x0
  1006da:	eb 29                	jmp    100705 <skip_atoi+0x47>
  1006dc:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  1006df:	89 d0                	mov    eax,edx
  1006e1:	c1 e0 02             	shl    eax,0x2
  1006e4:	01 d0                	add    eax,edx
  1006e6:	01 c0                	add    eax,eax
  1006e8:	89 c3                	mov    ebx,eax
  1006ea:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1006ed:	8b 00                	mov    eax,DWORD PTR [eax]
  1006ef:	8d 48 01             	lea    ecx,[eax+0x1]
  1006f2:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  1006f5:	89 0a                	mov    DWORD PTR [edx],ecx
  1006f7:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  1006fa:	0f be c0             	movsx  eax,al
  1006fd:	01 d8                	add    eax,ebx
  1006ff:	83 e8 30             	sub    eax,0x30
  100702:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  100705:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100708:	8b 00                	mov    eax,DWORD PTR [eax]
  10070a:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  10070d:	3c 2f                	cmp    al,0x2f
  10070f:	7e 0c                	jle    10071d <skip_atoi+0x5f>
  100711:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100714:	8b 00                	mov    eax,DWORD PTR [eax]
  100716:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100719:	3c 39                	cmp    al,0x39
  10071b:	7e bf                	jle    1006dc <skip_atoi+0x1e>
  10071d:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  100720:	83 c4 10             	add    esp,0x10
  100723:	5b                   	pop    ebx
  100724:	5d                   	pop    ebp
  100725:	c3                   	ret    

00100726 <number>:
  100726:	f3 0f 1e fb          	endbr32 
  10072a:	55                   	push   ebp
  10072b:	89 e5                	mov    ebp,esp
  10072d:	83 ec 40             	sub    esp,0x40
  100730:	e8 cb 28 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  100735:	05 cb 38 00 00       	add    eax,0x38cb
  10073a:	8d 90 8c f0 ff ff    	lea    edx,[eax-0xf74]
  100740:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  100743:	8b 55 1c             	mov    edx,DWORD PTR [ebp+0x1c]
  100746:	83 e2 40             	and    edx,0x40
  100749:	85 d2                	test   edx,edx
  10074b:	74 09                	je     100756 <number+0x30>
  10074d:	8d 80 b4 f0 ff ff    	lea    eax,[eax-0xf4c]
  100753:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  100756:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  100759:	83 e0 10             	and    eax,0x10
  10075c:	85 c0                	test   eax,eax
  10075e:	74 04                	je     100764 <number+0x3e>
  100760:	83 65 1c fe          	and    DWORD PTR [ebp+0x1c],0xfffffffe
  100764:	83 7d 10 01          	cmp    DWORD PTR [ebp+0x10],0x1
  100768:	7e 06                	jle    100770 <number+0x4a>
  10076a:	83 7d 10 24          	cmp    DWORD PTR [ebp+0x10],0x24
  10076e:	7e 0a                	jle    10077a <number+0x54>
  100770:	b8 00 00 00 00       	mov    eax,0x0
  100775:	e9 e1 01 00 00       	jmp    10095b <number+0x235>
  10077a:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  10077d:	83 e0 01             	and    eax,0x1
  100780:	85 c0                	test   eax,eax
  100782:	74 07                	je     10078b <number+0x65>
  100784:	b8 30 00 00 00       	mov    eax,0x30
  100789:	eb 05                	jmp    100790 <number+0x6a>
  10078b:	b8 20 00 00 00       	mov    eax,0x20
  100790:	88 45 f3             	mov    BYTE PTR [ebp-0xd],al
  100793:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  100796:	83 e0 02             	and    eax,0x2
  100799:	85 c0                	test   eax,eax
  10079b:	74 0f                	je     1007ac <number+0x86>
  10079d:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  1007a1:	79 09                	jns    1007ac <number+0x86>
  1007a3:	c6 45 ff 2d          	mov    BYTE PTR [ebp-0x1],0x2d
  1007a7:	f7 5d 0c             	neg    DWORD PTR [ebp+0xc]
  1007aa:	eb 1d                	jmp    1007c9 <number+0xa3>
  1007ac:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  1007af:	83 e0 04             	and    eax,0x4
  1007b2:	85 c0                	test   eax,eax
  1007b4:	75 0b                	jne    1007c1 <number+0x9b>
  1007b6:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  1007b9:	c1 e0 02             	shl    eax,0x2
  1007bc:	83 e0 20             	and    eax,0x20
  1007bf:	eb 05                	jmp    1007c6 <number+0xa0>
  1007c1:	b8 2b 00 00 00       	mov    eax,0x2b
  1007c6:	88 45 ff             	mov    BYTE PTR [ebp-0x1],al
  1007c9:	80 7d ff 00          	cmp    BYTE PTR [ebp-0x1],0x0
  1007cd:	74 04                	je     1007d3 <number+0xad>
  1007cf:	83 6d 14 01          	sub    DWORD PTR [ebp+0x14],0x1
  1007d3:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  1007d6:	83 e0 20             	and    eax,0x20
  1007d9:	85 c0                	test   eax,eax
  1007db:	74 16                	je     1007f3 <number+0xcd>
  1007dd:	83 7d 10 10          	cmp    DWORD PTR [ebp+0x10],0x10
  1007e1:	75 06                	jne    1007e9 <number+0xc3>
  1007e3:	83 6d 14 02          	sub    DWORD PTR [ebp+0x14],0x2
  1007e7:	eb 0a                	jmp    1007f3 <number+0xcd>
  1007e9:	83 7d 10 08          	cmp    DWORD PTR [ebp+0x10],0x8
  1007ed:	75 04                	jne    1007f3 <number+0xcd>
  1007ef:	83 6d 14 01          	sub    DWORD PTR [ebp+0x14],0x1
  1007f3:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  1007fa:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  1007fe:	75 3e                	jne    10083e <number+0x118>
  100800:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100803:	8d 50 01             	lea    edx,[eax+0x1]
  100806:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  100809:	c6 44 05 c8 30       	mov    BYTE PTR [ebp+eax*1-0x38],0x30
  10080e:	eb 34                	jmp    100844 <number+0x11e>
  100810:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100813:	ba 00 00 00 00       	mov    edx,0x0
  100818:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  10081b:	f7 f1                	div    ecx
  10081d:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  100820:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  100823:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  100826:	89 c2                	mov    edx,eax
  100828:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  10082b:	8d 0c 02             	lea    ecx,[edx+eax*1]
  10082e:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100831:	8d 50 01             	lea    edx,[eax+0x1]
  100834:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  100837:	0f b6 11             	movzx  edx,BYTE PTR [ecx]
  10083a:	88 54 05 c8          	mov    BYTE PTR [ebp+eax*1-0x38],dl
  10083e:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  100842:	75 cc                	jne    100810 <number+0xea>
  100844:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100847:	3b 45 18             	cmp    eax,DWORD PTR [ebp+0x18]
  10084a:	7e 06                	jle    100852 <number+0x12c>
  10084c:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10084f:	89 45 18             	mov    DWORD PTR [ebp+0x18],eax
  100852:	8b 45 18             	mov    eax,DWORD PTR [ebp+0x18]
  100855:	29 45 14             	sub    DWORD PTR [ebp+0x14],eax
  100858:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  10085b:	83 e0 11             	and    eax,0x11
  10085e:	85 c0                	test   eax,eax
  100860:	75 1b                	jne    10087d <number+0x157>
  100862:	eb 0c                	jmp    100870 <number+0x14a>
  100864:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100867:	8d 50 01             	lea    edx,[eax+0x1]
  10086a:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  10086d:	c6 00 20             	mov    BYTE PTR [eax],0x20
  100870:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  100873:	8d 50 ff             	lea    edx,[eax-0x1]
  100876:	89 55 14             	mov    DWORD PTR [ebp+0x14],edx
  100879:	85 c0                	test   eax,eax
  10087b:	7f e7                	jg     100864 <number+0x13e>
  10087d:	80 7d ff 00          	cmp    BYTE PTR [ebp-0x1],0x0
  100881:	74 0f                	je     100892 <number+0x16c>
  100883:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100886:	8d 50 01             	lea    edx,[eax+0x1]
  100889:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  10088c:	0f b6 55 ff          	movzx  edx,BYTE PTR [ebp-0x1]
  100890:	88 10                	mov    BYTE PTR [eax],dl
  100892:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  100895:	83 e0 20             	and    eax,0x20
  100898:	85 c0                	test   eax,eax
  10089a:	74 38                	je     1008d4 <number+0x1ae>
  10089c:	83 7d 10 08          	cmp    DWORD PTR [ebp+0x10],0x8
  1008a0:	75 0e                	jne    1008b0 <number+0x18a>
  1008a2:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1008a5:	8d 50 01             	lea    edx,[eax+0x1]
  1008a8:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  1008ab:	c6 00 30             	mov    BYTE PTR [eax],0x30
  1008ae:	eb 24                	jmp    1008d4 <number+0x1ae>
  1008b0:	83 7d 10 10          	cmp    DWORD PTR [ebp+0x10],0x10
  1008b4:	75 1e                	jne    1008d4 <number+0x1ae>
  1008b6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1008b9:	8d 50 01             	lea    edx,[eax+0x1]
  1008bc:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  1008bf:	c6 00 30             	mov    BYTE PTR [eax],0x30
  1008c2:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1008c5:	8d 50 01             	lea    edx,[eax+0x1]
  1008c8:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  1008cb:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  1008ce:	0f b6 52 21          	movzx  edx,BYTE PTR [edx+0x21]
  1008d2:	88 10                	mov    BYTE PTR [eax],dl
  1008d4:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  1008d7:	83 e0 10             	and    eax,0x10
  1008da:	85 c0                	test   eax,eax
  1008dc:	75 2c                	jne    10090a <number+0x1e4>
  1008de:	eb 0f                	jmp    1008ef <number+0x1c9>
  1008e0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1008e3:	8d 50 01             	lea    edx,[eax+0x1]
  1008e6:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  1008e9:	0f b6 55 f3          	movzx  edx,BYTE PTR [ebp-0xd]
  1008ed:	88 10                	mov    BYTE PTR [eax],dl
  1008ef:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  1008f2:	8d 50 ff             	lea    edx,[eax-0x1]
  1008f5:	89 55 14             	mov    DWORD PTR [ebp+0x14],edx
  1008f8:	85 c0                	test   eax,eax
  1008fa:	7f e4                	jg     1008e0 <number+0x1ba>
  1008fc:	eb 0c                	jmp    10090a <number+0x1e4>
  1008fe:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100901:	8d 50 01             	lea    edx,[eax+0x1]
  100904:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  100907:	c6 00 30             	mov    BYTE PTR [eax],0x30
  10090a:	8b 45 18             	mov    eax,DWORD PTR [ebp+0x18]
  10090d:	8d 50 ff             	lea    edx,[eax-0x1]
  100910:	89 55 18             	mov    DWORD PTR [ebp+0x18],edx
  100913:	39 45 f4             	cmp    DWORD PTR [ebp-0xc],eax
  100916:	7c e6                	jl     1008fe <number+0x1d8>
  100918:	eb 16                	jmp    100930 <number+0x20a>
  10091a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  10091d:	8d 50 01             	lea    edx,[eax+0x1]
  100920:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  100923:	8d 4d c8             	lea    ecx,[ebp-0x38]
  100926:	8b 55 f4             	mov    edx,DWORD PTR [ebp-0xc]
  100929:	01 ca                	add    edx,ecx
  10092b:	0f b6 12             	movzx  edx,BYTE PTR [edx]
  10092e:	88 10                	mov    BYTE PTR [eax],dl
  100930:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100933:	8d 50 ff             	lea    edx,[eax-0x1]
  100936:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  100939:	85 c0                	test   eax,eax
  10093b:	7f dd                	jg     10091a <number+0x1f4>
  10093d:	eb 0c                	jmp    10094b <number+0x225>
  10093f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100942:	8d 50 01             	lea    edx,[eax+0x1]
  100945:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  100948:	c6 00 20             	mov    BYTE PTR [eax],0x20
  10094b:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  10094e:	8d 50 ff             	lea    edx,[eax-0x1]
  100951:	89 55 14             	mov    DWORD PTR [ebp+0x14],edx
  100954:	85 c0                	test   eax,eax
  100956:	7f e7                	jg     10093f <number+0x219>
  100958:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  10095b:	c9                   	leave  
  10095c:	c3                   	ret    

0010095d <vsprintf>:
  10095d:	f3 0f 1e fb          	endbr32 
  100961:	55                   	push   ebp
  100962:	89 e5                	mov    ebp,esp
  100964:	53                   	push   ebx
  100965:	83 ec 20             	sub    esp,0x20
  100968:	e8 97 26 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  10096d:	81 c3 93 36 00 00    	add    ebx,0x3693
  100973:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100976:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100979:	e9 bb 03 00 00       	jmp    100d39 <.L67+0x46>
  10097e:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100981:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100984:	3c 25                	cmp    al,0x25
  100986:	74 16                	je     10099e <vsprintf+0x41>
  100988:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  10098b:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  10098e:	8d 48 01             	lea    ecx,[eax+0x1]
  100991:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  100994:	0f b6 12             	movzx  edx,BYTE PTR [edx]
  100997:	88 10                	mov    BYTE PTR [eax],dl
  100999:	e9 92 03 00 00       	jmp    100d30 <.L67+0x3d>
  10099e:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  1009a5:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  1009a8:	83 c0 01             	add    eax,0x1
  1009ab:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  1009ae:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  1009b1:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  1009b4:	0f be c0             	movsx  eax,al
  1009b7:	83 e8 20             	sub    eax,0x20
  1009ba:	83 f8 10             	cmp    eax,0x10
  1009bd:	77 2d                	ja     1009ec <.L53>
  1009bf:	c1 e0 02             	shl    eax,0x2
  1009c2:	8b 84 18 dc f0 ff ff 	mov    eax,DWORD PTR [eax+ebx*1-0xf24]
  1009c9:	01 d8                	add    eax,ebx
  1009cb:	3e ff e0             	notrack jmp eax

001009ce <.L56>:
  1009ce:	83 4d e8 10          	or     DWORD PTR [ebp-0x18],0x10
  1009d2:	eb d1                	jmp    1009a5 <vsprintf+0x48>

001009d4 <.L57>:
  1009d4:	83 4d e8 04          	or     DWORD PTR [ebp-0x18],0x4
  1009d8:	eb cb                	jmp    1009a5 <vsprintf+0x48>

001009da <.L59>:
  1009da:	83 4d e8 08          	or     DWORD PTR [ebp-0x18],0x8
  1009de:	eb c5                	jmp    1009a5 <vsprintf+0x48>

001009e0 <.L58>:
  1009e0:	83 4d e8 20          	or     DWORD PTR [ebp-0x18],0x20
  1009e4:	eb bf                	jmp    1009a5 <vsprintf+0x48>

001009e6 <.L54>:
  1009e6:	83 4d e8 01          	or     DWORD PTR [ebp-0x18],0x1
  1009ea:	eb b9                	jmp    1009a5 <vsprintf+0x48>

001009ec <.L53>:
  1009ec:	c7 45 e4 ff ff ff ff 	mov    DWORD PTR [ebp-0x1c],0xffffffff
  1009f3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  1009f6:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  1009f9:	3c 2f                	cmp    al,0x2f
  1009fb:	7e 1b                	jle    100a18 <.L53+0x2c>
  1009fd:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a00:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100a03:	3c 39                	cmp    al,0x39
  100a05:	7f 11                	jg     100a18 <.L53+0x2c>
  100a07:	8d 45 0c             	lea    eax,[ebp+0xc]
  100a0a:	50                   	push   eax
  100a0b:	e8 ae fc ff ff       	call   1006be <skip_atoi>
  100a10:	83 c4 04             	add    esp,0x4
  100a13:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  100a16:	eb 25                	jmp    100a3d <.L53+0x51>
  100a18:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a1b:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100a1e:	3c 2a                	cmp    al,0x2a
  100a20:	75 1b                	jne    100a3d <.L53+0x51>
  100a22:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100a25:	8d 50 04             	lea    edx,[eax+0x4]
  100a28:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100a2b:	8b 00                	mov    eax,DWORD PTR [eax]
  100a2d:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  100a30:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  100a34:	79 07                	jns    100a3d <.L53+0x51>
  100a36:	f7 5d e4             	neg    DWORD PTR [ebp-0x1c]
  100a39:	83 4d e8 10          	or     DWORD PTR [ebp-0x18],0x10
  100a3d:	c7 45 e0 ff ff ff ff 	mov    DWORD PTR [ebp-0x20],0xffffffff
  100a44:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a47:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100a4a:	3c 2e                	cmp    al,0x2e
  100a4c:	75 53                	jne    100aa1 <.L53+0xb5>
  100a4e:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a51:	83 c0 01             	add    eax,0x1
  100a54:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  100a57:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a5a:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100a5d:	3c 2f                	cmp    al,0x2f
  100a5f:	7e 1b                	jle    100a7c <.L53+0x90>
  100a61:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a64:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100a67:	3c 39                	cmp    al,0x39
  100a69:	7f 11                	jg     100a7c <.L53+0x90>
  100a6b:	8d 45 0c             	lea    eax,[ebp+0xc]
  100a6e:	50                   	push   eax
  100a6f:	e8 4a fc ff ff       	call   1006be <skip_atoi>
  100a74:	83 c4 04             	add    esp,0x4
  100a77:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  100a7a:	eb 18                	jmp    100a94 <.L53+0xa8>
  100a7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100a7f:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100a82:	3c 2a                	cmp    al,0x2a
  100a84:	75 0e                	jne    100a94 <.L53+0xa8>
  100a86:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100a89:	8d 50 04             	lea    edx,[eax+0x4]
  100a8c:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100a8f:	8b 00                	mov    eax,DWORD PTR [eax]
  100a91:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  100a94:	83 7d e0 00          	cmp    DWORD PTR [ebp-0x20],0x0
  100a98:	79 07                	jns    100aa1 <.L53+0xb5>
  100a9a:	c7 45 e0 00 00 00 00 	mov    DWORD PTR [ebp-0x20],0x0
  100aa1:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100aa4:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100aa7:	3c 68                	cmp    al,0x68
  100aa9:	74 14                	je     100abf <.L53+0xd3>
  100aab:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100aae:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100ab1:	3c 6c                	cmp    al,0x6c
  100ab3:	74 0a                	je     100abf <.L53+0xd3>
  100ab5:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100ab8:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100abb:	3c 4c                	cmp    al,0x4c
  100abd:	75 09                	jne    100ac8 <.L53+0xdc>
  100abf:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100ac2:	83 c0 01             	add    eax,0x1
  100ac5:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  100ac8:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100acb:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100ace:	0f be c0             	movsx  eax,al
  100ad1:	83 e8 58             	sub    eax,0x58
  100ad4:	83 f8 20             	cmp    eax,0x20
  100ad7:	0f 87 16 02 00 00    	ja     100cf3 <.L67>
  100add:	c1 e0 02             	shl    eax,0x2
  100ae0:	8b 84 18 20 f1 ff ff 	mov    eax,DWORD PTR [eax+ebx*1-0xee0]
  100ae7:	01 d8                	add    eax,ebx
  100ae9:	3e ff e0             	notrack jmp eax

00100aec <.L76>:
  100aec:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  100aef:	83 e0 10             	and    eax,0x10
  100af2:	85 c0                	test   eax,eax
  100af4:	75 18                	jne    100b0e <.L76+0x22>
  100af6:	eb 0c                	jmp    100b04 <.L76+0x18>
  100af8:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100afb:	8d 50 01             	lea    edx,[eax+0x1]
  100afe:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  100b01:	c6 00 20             	mov    BYTE PTR [eax],0x20
  100b04:	83 6d e4 01          	sub    DWORD PTR [ebp-0x1c],0x1
  100b08:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  100b0c:	7f ea                	jg     100af8 <.L76+0xc>
  100b0e:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100b11:	8d 50 04             	lea    edx,[eax+0x4]
  100b14:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100b17:	8b 08                	mov    ecx,DWORD PTR [eax]
  100b19:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100b1c:	8d 50 01             	lea    edx,[eax+0x1]
  100b1f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  100b22:	89 ca                	mov    edx,ecx
  100b24:	88 10                	mov    BYTE PTR [eax],dl
  100b26:	eb 0c                	jmp    100b34 <.L76+0x48>
  100b28:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100b2b:	8d 50 01             	lea    edx,[eax+0x1]
  100b2e:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  100b31:	c6 00 20             	mov    BYTE PTR [eax],0x20
  100b34:	83 6d e4 01          	sub    DWORD PTR [ebp-0x1c],0x1
  100b38:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  100b3c:	7f ea                	jg     100b28 <.L76+0x3c>
  100b3e:	e9 ed 01 00 00       	jmp    100d30 <.L67+0x3d>

00100b43 <.L71>:
  100b43:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100b46:	8d 50 04             	lea    edx,[eax+0x4]
  100b49:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100b4c:	8b 00                	mov    eax,DWORD PTR [eax]
  100b4e:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  100b51:	ff 75 ec             	push   DWORD PTR [ebp-0x14]
  100b54:	e8 75 fa ff ff       	call   1005ce <strlen>
  100b59:	83 c4 04             	add    esp,0x4
  100b5c:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  100b5f:	83 7d e0 00          	cmp    DWORD PTR [ebp-0x20],0x0
  100b63:	79 08                	jns    100b6d <.L71+0x2a>
  100b65:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  100b68:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  100b6b:	eb 0e                	jmp    100b7b <.L71+0x38>
  100b6d:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  100b70:	3b 45 e0             	cmp    eax,DWORD PTR [ebp-0x20]
  100b73:	7e 06                	jle    100b7b <.L71+0x38>
  100b75:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  100b78:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  100b7b:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  100b7e:	83 e0 10             	and    eax,0x10
  100b81:	85 c0                	test   eax,eax
  100b83:	75 1c                	jne    100ba1 <.L71+0x5e>
  100b85:	eb 0c                	jmp    100b93 <.L71+0x50>
  100b87:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100b8a:	8d 50 01             	lea    edx,[eax+0x1]
  100b8d:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  100b90:	c6 00 20             	mov    BYTE PTR [eax],0x20
  100b93:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  100b96:	8d 50 ff             	lea    edx,[eax-0x1]
  100b99:	89 55 e4             	mov    DWORD PTR [ebp-0x1c],edx
  100b9c:	39 45 f8             	cmp    DWORD PTR [ebp-0x8],eax
  100b9f:	7c e6                	jl     100b87 <.L71+0x44>
  100ba1:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  100ba8:	eb 1b                	jmp    100bc5 <.L71+0x82>
  100baa:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  100bad:	8d 42 01             	lea    eax,[edx+0x1]
  100bb0:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  100bb3:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100bb6:	8d 48 01             	lea    ecx,[eax+0x1]
  100bb9:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  100bbc:	0f b6 12             	movzx  edx,BYTE PTR [edx]
  100bbf:	88 10                	mov    BYTE PTR [eax],dl
  100bc1:	83 45 f4 01          	add    DWORD PTR [ebp-0xc],0x1
  100bc5:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  100bc8:	3b 45 f8             	cmp    eax,DWORD PTR [ebp-0x8]
  100bcb:	7c dd                	jl     100baa <.L71+0x67>
  100bcd:	eb 0c                	jmp    100bdb <.L71+0x98>
  100bcf:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100bd2:	8d 50 01             	lea    edx,[eax+0x1]
  100bd5:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  100bd8:	c6 00 20             	mov    BYTE PTR [eax],0x20
  100bdb:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  100bde:	8d 50 ff             	lea    edx,[eax-0x1]
  100be1:	89 55 e4             	mov    DWORD PTR [ebp-0x1c],edx
  100be4:	39 45 f8             	cmp    DWORD PTR [ebp-0x8],eax
  100be7:	7c e6                	jl     100bcf <.L71+0x8c>
  100be9:	e9 42 01 00 00       	jmp    100d30 <.L67+0x3d>

00100bee <.L73>:
  100bee:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100bf1:	8d 50 04             	lea    edx,[eax+0x4]
  100bf4:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100bf7:	8b 00                	mov    eax,DWORD PTR [eax]
  100bf9:	ff 75 e8             	push   DWORD PTR [ebp-0x18]
  100bfc:	ff 75 e0             	push   DWORD PTR [ebp-0x20]
  100bff:	ff 75 e4             	push   DWORD PTR [ebp-0x1c]
  100c02:	6a 08                	push   0x8
  100c04:	50                   	push   eax
  100c05:	ff 75 f0             	push   DWORD PTR [ebp-0x10]
  100c08:	e8 19 fb ff ff       	call   100726 <number>
  100c0d:	83 c4 18             	add    esp,0x18
  100c10:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100c13:	e9 18 01 00 00       	jmp    100d30 <.L67+0x3d>

00100c18 <.L72>:
  100c18:	83 7d e4 ff          	cmp    DWORD PTR [ebp-0x1c],0xffffffff
  100c1c:	75 0b                	jne    100c29 <.L72+0x11>
  100c1e:	c7 45 e4 08 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x8
  100c25:	83 4d e8 01          	or     DWORD PTR [ebp-0x18],0x1
  100c29:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100c2c:	8d 50 04             	lea    edx,[eax+0x4]
  100c2f:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100c32:	8b 00                	mov    eax,DWORD PTR [eax]
  100c34:	ff 75 e8             	push   DWORD PTR [ebp-0x18]
  100c37:	ff 75 e0             	push   DWORD PTR [ebp-0x20]
  100c3a:	ff 75 e4             	push   DWORD PTR [ebp-0x1c]
  100c3d:	6a 10                	push   0x10
  100c3f:	50                   	push   eax
  100c40:	ff 75 f0             	push   DWORD PTR [ebp-0x10]
  100c43:	e8 de fa ff ff       	call   100726 <number>
  100c48:	83 c4 18             	add    esp,0x18
  100c4b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100c4e:	e9 dd 00 00 00       	jmp    100d30 <.L67+0x3d>

00100c53 <.L68>:
  100c53:	83 4d e8 40          	or     DWORD PTR [ebp-0x18],0x40

00100c57 <.L78>:
  100c57:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100c5a:	8d 50 04             	lea    edx,[eax+0x4]
  100c5d:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100c60:	8b 00                	mov    eax,DWORD PTR [eax]
  100c62:	ff 75 e8             	push   DWORD PTR [ebp-0x18]
  100c65:	ff 75 e0             	push   DWORD PTR [ebp-0x20]
  100c68:	ff 75 e4             	push   DWORD PTR [ebp-0x1c]
  100c6b:	6a 10                	push   0x10
  100c6d:	50                   	push   eax
  100c6e:	ff 75 f0             	push   DWORD PTR [ebp-0x10]
  100c71:	e8 b0 fa ff ff       	call   100726 <number>
  100c76:	83 c4 18             	add    esp,0x18
  100c79:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100c7c:	e9 af 00 00 00       	jmp    100d30 <.L67+0x3d>

00100c81 <.L75>:
  100c81:	83 4d e8 02          	or     DWORD PTR [ebp-0x18],0x2

00100c85 <.L70>:
  100c85:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100c88:	8d 50 04             	lea    edx,[eax+0x4]
  100c8b:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100c8e:	8b 00                	mov    eax,DWORD PTR [eax]
  100c90:	ff 75 e8             	push   DWORD PTR [ebp-0x18]
  100c93:	ff 75 e0             	push   DWORD PTR [ebp-0x20]
  100c96:	ff 75 e4             	push   DWORD PTR [ebp-0x1c]
  100c99:	6a 0a                	push   0xa
  100c9b:	50                   	push   eax
  100c9c:	ff 75 f0             	push   DWORD PTR [ebp-0x10]
  100c9f:	e8 82 fa ff ff       	call   100726 <number>
  100ca4:	83 c4 18             	add    esp,0x18
  100ca7:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100caa:	e9 81 00 00 00       	jmp    100d30 <.L67+0x3d>

00100caf <.L77>:
  100caf:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100cb2:	8d 50 04             	lea    edx,[eax+0x4]
  100cb5:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100cb8:	8b 00                	mov    eax,DWORD PTR [eax]
  100cba:	ff 75 e8             	push   DWORD PTR [ebp-0x18]
  100cbd:	ff 75 e0             	push   DWORD PTR [ebp-0x20]
  100cc0:	ff 75 e4             	push   DWORD PTR [ebp-0x1c]
  100cc3:	6a 02                	push   0x2
  100cc5:	50                   	push   eax
  100cc6:	ff 75 f0             	push   DWORD PTR [ebp-0x10]
  100cc9:	e8 58 fa ff ff       	call   100726 <number>
  100cce:	83 c4 18             	add    esp,0x18
  100cd1:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  100cd4:	eb 5a                	jmp    100d30 <.L67+0x3d>

00100cd6 <.L74>:
  100cd6:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  100cd9:	8d 50 04             	lea    edx,[eax+0x4]
  100cdc:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  100cdf:	8b 00                	mov    eax,DWORD PTR [eax]
  100ce1:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  100ce4:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100ce7:	2b 45 08             	sub    eax,DWORD PTR [ebp+0x8]
  100cea:	89 c2                	mov    edx,eax
  100cec:	8b 45 dc             	mov    eax,DWORD PTR [ebp-0x24]
  100cef:	89 10                	mov    DWORD PTR [eax],edx
  100cf1:	eb 3d                	jmp    100d30 <.L67+0x3d>

00100cf3 <.L67>:
  100cf3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100cf6:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100cf9:	3c 25                	cmp    al,0x25
  100cfb:	74 0c                	je     100d09 <.L67+0x16>
  100cfd:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100d00:	8d 50 01             	lea    edx,[eax+0x1]
  100d03:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  100d06:	c6 00 25             	mov    BYTE PTR [eax],0x25
  100d09:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100d0c:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100d0f:	84 c0                	test   al,al
  100d11:	74 13                	je     100d26 <.L67+0x33>
  100d13:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  100d16:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100d19:	8d 48 01             	lea    ecx,[eax+0x1]
  100d1c:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  100d1f:	0f b6 12             	movzx  edx,BYTE PTR [edx]
  100d22:	88 10                	mov    BYTE PTR [eax],dl
  100d24:	eb 09                	jmp    100d2f <.L67+0x3c>
  100d26:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100d29:	83 e8 01             	sub    eax,0x1
  100d2c:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  100d2f:	90                   	nop
  100d30:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100d33:	83 c0 01             	add    eax,0x1
  100d36:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  100d39:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100d3c:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  100d3f:	84 c0                	test   al,al
  100d41:	0f 85 37 fc ff ff    	jne    10097e <vsprintf+0x21>
  100d47:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100d4a:	c6 00 00             	mov    BYTE PTR [eax],0x0
  100d4d:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  100d50:	2b 45 08             	sub    eax,DWORD PTR [ebp+0x8]
  100d53:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  100d56:	c9                   	leave  
  100d57:	c3                   	ret    

00100d58 <memset>:
  100d58:	55                   	push   ebp
  100d59:	89 e5                	mov    ebp,esp
  100d5b:	83 ec 14             	sub    esp,0x14
  100d5e:	e8 9d 22 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  100d63:	05 9d 32 00 00       	add    eax,0x329d
  100d68:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  100d6b:	88 45 ec             	mov    BYTE PTR [ebp-0x14],al
  100d6e:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  100d71:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  100d74:	eb 13                	jmp    100d89 <memset+0x31>
  100d76:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  100d79:	8d 50 01             	lea    edx,[eax+0x1]
  100d7c:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  100d7f:	0f b6 55 ec          	movzx  edx,BYTE PTR [ebp-0x14]
  100d83:	88 10                	mov    BYTE PTR [eax],dl
  100d85:	83 6d 10 01          	sub    DWORD PTR [ebp+0x10],0x1
  100d89:	83 7d 10 00          	cmp    DWORD PTR [ebp+0x10],0x0
  100d8d:	75 e7                	jne    100d76 <memset+0x1e>
  100d8f:	90                   	nop
  100d90:	90                   	nop
  100d91:	c9                   	leave  
  100d92:	c3                   	ret    

00100d93 <bzero>:
  100d93:	55                   	push   ebp
  100d94:	89 e5                	mov    ebp,esp
  100d96:	e8 65 22 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  100d9b:	05 65 32 00 00       	add    eax,0x3265
  100da0:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  100da3:	6a 00                	push   0x0
  100da5:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  100da8:	e8 ab ff ff ff       	call   100d58 <memset>
  100dad:	83 c4 0c             	add    esp,0xc
  100db0:	90                   	nop
  100db1:	c9                   	leave  
  100db2:	c3                   	ret    

00100db3 <init_idt>:
  100db3:	f3 0f 1e fb          	endbr32 
  100db7:	55                   	push   ebp
  100db8:	89 e5                	mov    ebp,esp
  100dba:	53                   	push   ebx
  100dbb:	83 ec 04             	sub    esp,0x4
  100dbe:	e8 41 22 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  100dc3:	81 c3 3d 32 00 00    	add    ebx,0x323d
  100dc9:	83 ec 08             	sub    esp,0x8
  100dcc:	6a 11                	push   0x11
  100dce:	6a 20                	push   0x20
  100dd0:	e8 a5 0b 00 00       	call   10197a <outb>
  100dd5:	83 c4 10             	add    esp,0x10
  100dd8:	83 ec 08             	sub    esp,0x8
  100ddb:	6a 11                	push   0x11
  100ddd:	68 a0 00 00 00       	push   0xa0
  100de2:	e8 93 0b 00 00       	call   10197a <outb>
  100de7:	83 c4 10             	add    esp,0x10
  100dea:	83 ec 08             	sub    esp,0x8
  100ded:	6a 20                	push   0x20
  100def:	6a 21                	push   0x21
  100df1:	e8 84 0b 00 00       	call   10197a <outb>
  100df6:	83 c4 10             	add    esp,0x10
  100df9:	83 ec 08             	sub    esp,0x8
  100dfc:	6a 28                	push   0x28
  100dfe:	68 a1 00 00 00       	push   0xa1
  100e03:	e8 72 0b 00 00       	call   10197a <outb>
  100e08:	83 c4 10             	add    esp,0x10
  100e0b:	83 ec 08             	sub    esp,0x8
  100e0e:	6a 04                	push   0x4
  100e10:	6a 21                	push   0x21
  100e12:	e8 63 0b 00 00       	call   10197a <outb>
  100e17:	83 c4 10             	add    esp,0x10
  100e1a:	83 ec 08             	sub    esp,0x8
  100e1d:	6a 02                	push   0x2
  100e1f:	68 a1 00 00 00       	push   0xa1
  100e24:	e8 51 0b 00 00       	call   10197a <outb>
  100e29:	83 c4 10             	add    esp,0x10
  100e2c:	83 ec 08             	sub    esp,0x8
  100e2f:	6a 01                	push   0x1
  100e31:	6a 21                	push   0x21
  100e33:	e8 42 0b 00 00       	call   10197a <outb>
  100e38:	83 c4 10             	add    esp,0x10
  100e3b:	83 ec 08             	sub    esp,0x8
  100e3e:	6a 01                	push   0x1
  100e40:	68 a1 00 00 00       	push   0xa1
  100e45:	e8 30 0b 00 00       	call   10197a <outb>
  100e4a:	83 c4 10             	add    esp,0x10
  100e4d:	83 ec 08             	sub    esp,0x8
  100e50:	6a 00                	push   0x0
  100e52:	6a 21                	push   0x21
  100e54:	e8 21 0b 00 00       	call   10197a <outb>
  100e59:	83 c4 10             	add    esp,0x10
  100e5c:	83 ec 08             	sub    esp,0x8
  100e5f:	6a 00                	push   0x0
  100e61:	68 a1 00 00 00       	push   0xa1
  100e66:	e8 0f 0b 00 00       	call   10197a <outb>
  100e6b:	83 c4 10             	add    esp,0x10
  100e6e:	83 ec 08             	sub    esp,0x8
  100e71:	68 00 04 00 00       	push   0x400
  100e76:	c7 c0 60 d8 18 00    	mov    eax,0x18d860
  100e7c:	50                   	push   eax
  100e7d:	e8 11 ff ff ff       	call   100d93 <bzero>
  100e82:	83 c4 10             	add    esp,0x10
  100e85:	c7 c0 40 d0 18 00    	mov    eax,0x18d040
  100e8b:	66 c7 00 ff 07       	mov    WORD PTR [eax],0x7ff
  100e90:	c7 c0 60 d0 18 00    	mov    eax,0x18d060
  100e96:	89 c2                	mov    edx,eax
  100e98:	c7 c0 40 d0 18 00    	mov    eax,0x18d040
  100e9e:	89 50 02             	mov    DWORD PTR [eax+0x2],edx
  100ea1:	83 ec 08             	sub    esp,0x8
  100ea4:	68 00 08 00 00       	push   0x800
  100ea9:	c7 c0 60 d0 18 00    	mov    eax,0x18d060
  100eaf:	50                   	push   eax
  100eb0:	e8 de fe ff ff       	call   100d93 <bzero>
  100eb5:	83 c4 10             	add    esp,0x10
  100eb8:	c7 c0 58 00 10 00    	mov    eax,0x100058
  100ebe:	68 8e 00 00 00       	push   0x8e
  100ec3:	6a 08                	push   0x8
  100ec5:	50                   	push   eax
  100ec6:	6a 00                	push   0x0
  100ec8:	e8 9e 04 00 00       	call   10136b <idt_set_gate>
  100ecd:	83 c4 10             	add    esp,0x10
  100ed0:	c7 c0 62 00 10 00    	mov    eax,0x100062
  100ed6:	68 8e 00 00 00       	push   0x8e
  100edb:	6a 08                	push   0x8
  100edd:	50                   	push   eax
  100ede:	6a 01                	push   0x1
  100ee0:	e8 86 04 00 00       	call   10136b <idt_set_gate>
  100ee5:	83 c4 10             	add    esp,0x10
  100ee8:	c7 c0 6c 00 10 00    	mov    eax,0x10006c
  100eee:	68 8e 00 00 00       	push   0x8e
  100ef3:	6a 08                	push   0x8
  100ef5:	50                   	push   eax
  100ef6:	6a 02                	push   0x2
  100ef8:	e8 6e 04 00 00       	call   10136b <idt_set_gate>
  100efd:	83 c4 10             	add    esp,0x10
  100f00:	c7 c0 76 00 10 00    	mov    eax,0x100076
  100f06:	68 8e 00 00 00       	push   0x8e
  100f0b:	6a 08                	push   0x8
  100f0d:	50                   	push   eax
  100f0e:	6a 03                	push   0x3
  100f10:	e8 56 04 00 00       	call   10136b <idt_set_gate>
  100f15:	83 c4 10             	add    esp,0x10
  100f18:	c7 c0 80 00 10 00    	mov    eax,0x100080
  100f1e:	68 8e 00 00 00       	push   0x8e
  100f23:	6a 08                	push   0x8
  100f25:	50                   	push   eax
  100f26:	6a 04                	push   0x4
  100f28:	e8 3e 04 00 00       	call   10136b <idt_set_gate>
  100f2d:	83 c4 10             	add    esp,0x10
  100f30:	c7 c0 8a 00 10 00    	mov    eax,0x10008a
  100f36:	68 8e 00 00 00       	push   0x8e
  100f3b:	6a 08                	push   0x8
  100f3d:	50                   	push   eax
  100f3e:	6a 05                	push   0x5
  100f40:	e8 26 04 00 00       	call   10136b <idt_set_gate>
  100f45:	83 c4 10             	add    esp,0x10
  100f48:	c7 c0 94 00 10 00    	mov    eax,0x100094
  100f4e:	68 8e 00 00 00       	push   0x8e
  100f53:	6a 08                	push   0x8
  100f55:	50                   	push   eax
  100f56:	6a 06                	push   0x6
  100f58:	e8 0e 04 00 00       	call   10136b <idt_set_gate>
  100f5d:	83 c4 10             	add    esp,0x10
  100f60:	c7 c0 9e 00 10 00    	mov    eax,0x10009e
  100f66:	68 8e 00 00 00       	push   0x8e
  100f6b:	6a 08                	push   0x8
  100f6d:	50                   	push   eax
  100f6e:	6a 07                	push   0x7
  100f70:	e8 f6 03 00 00       	call   10136b <idt_set_gate>
  100f75:	83 c4 10             	add    esp,0x10
  100f78:	c7 c0 a8 00 10 00    	mov    eax,0x1000a8
  100f7e:	68 8e 00 00 00       	push   0x8e
  100f83:	6a 08                	push   0x8
  100f85:	50                   	push   eax
  100f86:	6a 08                	push   0x8
  100f88:	e8 de 03 00 00       	call   10136b <idt_set_gate>
  100f8d:	83 c4 10             	add    esp,0x10
  100f90:	c7 c0 b0 00 10 00    	mov    eax,0x1000b0
  100f96:	68 8e 00 00 00       	push   0x8e
  100f9b:	6a 08                	push   0x8
  100f9d:	50                   	push   eax
  100f9e:	6a 09                	push   0x9
  100fa0:	e8 c6 03 00 00       	call   10136b <idt_set_gate>
  100fa5:	83 c4 10             	add    esp,0x10
  100fa8:	c7 c0 ba 00 10 00    	mov    eax,0x1000ba
  100fae:	68 8e 00 00 00       	push   0x8e
  100fb3:	6a 08                	push   0x8
  100fb5:	50                   	push   eax
  100fb6:	6a 0a                	push   0xa
  100fb8:	e8 ae 03 00 00       	call   10136b <idt_set_gate>
  100fbd:	83 c4 10             	add    esp,0x10
  100fc0:	c7 c0 c2 00 10 00    	mov    eax,0x1000c2
  100fc6:	68 8e 00 00 00       	push   0x8e
  100fcb:	6a 08                	push   0x8
  100fcd:	50                   	push   eax
  100fce:	6a 0b                	push   0xb
  100fd0:	e8 96 03 00 00       	call   10136b <idt_set_gate>
  100fd5:	83 c4 10             	add    esp,0x10
  100fd8:	c7 c0 ca 00 10 00    	mov    eax,0x1000ca
  100fde:	68 8e 00 00 00       	push   0x8e
  100fe3:	6a 08                	push   0x8
  100fe5:	50                   	push   eax
  100fe6:	6a 0c                	push   0xc
  100fe8:	e8 7e 03 00 00       	call   10136b <idt_set_gate>
  100fed:	83 c4 10             	add    esp,0x10
  100ff0:	c7 c0 d2 00 10 00    	mov    eax,0x1000d2
  100ff6:	68 8e 00 00 00       	push   0x8e
  100ffb:	6a 08                	push   0x8
  100ffd:	50                   	push   eax
  100ffe:	6a 0d                	push   0xd
  101000:	e8 66 03 00 00       	call   10136b <idt_set_gate>
  101005:	83 c4 10             	add    esp,0x10
  101008:	c7 c0 da 00 10 00    	mov    eax,0x1000da
  10100e:	68 8e 00 00 00       	push   0x8e
  101013:	6a 08                	push   0x8
  101015:	50                   	push   eax
  101016:	6a 0e                	push   0xe
  101018:	e8 4e 03 00 00       	call   10136b <idt_set_gate>
  10101d:	83 c4 10             	add    esp,0x10
  101020:	c7 c0 df 00 10 00    	mov    eax,0x1000df
  101026:	68 8e 00 00 00       	push   0x8e
  10102b:	6a 08                	push   0x8
  10102d:	50                   	push   eax
  10102e:	6a 0f                	push   0xf
  101030:	e8 36 03 00 00       	call   10136b <idt_set_gate>
  101035:	83 c4 10             	add    esp,0x10
  101038:	c7 c0 e6 00 10 00    	mov    eax,0x1000e6
  10103e:	68 8e 00 00 00       	push   0x8e
  101043:	6a 08                	push   0x8
  101045:	50                   	push   eax
  101046:	6a 10                	push   0x10
  101048:	e8 1e 03 00 00       	call   10136b <idt_set_gate>
  10104d:	83 c4 10             	add    esp,0x10
  101050:	c7 c0 ed 00 10 00    	mov    eax,0x1000ed
  101056:	68 8e 00 00 00       	push   0x8e
  10105b:	6a 08                	push   0x8
  10105d:	50                   	push   eax
  10105e:	6a 11                	push   0x11
  101060:	e8 06 03 00 00       	call   10136b <idt_set_gate>
  101065:	83 c4 10             	add    esp,0x10
  101068:	c7 c0 f2 00 10 00    	mov    eax,0x1000f2
  10106e:	68 8e 00 00 00       	push   0x8e
  101073:	6a 08                	push   0x8
  101075:	50                   	push   eax
  101076:	6a 12                	push   0x12
  101078:	e8 ee 02 00 00       	call   10136b <idt_set_gate>
  10107d:	83 c4 10             	add    esp,0x10
  101080:	c7 c0 f9 00 10 00    	mov    eax,0x1000f9
  101086:	68 8e 00 00 00       	push   0x8e
  10108b:	6a 08                	push   0x8
  10108d:	50                   	push   eax
  10108e:	6a 13                	push   0x13
  101090:	e8 d6 02 00 00       	call   10136b <idt_set_gate>
  101095:	83 c4 10             	add    esp,0x10
  101098:	c7 c0 00 01 10 00    	mov    eax,0x100100
  10109e:	68 8e 00 00 00       	push   0x8e
  1010a3:	6a 08                	push   0x8
  1010a5:	50                   	push   eax
  1010a6:	6a 14                	push   0x14
  1010a8:	e8 be 02 00 00       	call   10136b <idt_set_gate>
  1010ad:	83 c4 10             	add    esp,0x10
  1010b0:	c7 c0 07 01 10 00    	mov    eax,0x100107
  1010b6:	68 8e 00 00 00       	push   0x8e
  1010bb:	6a 08                	push   0x8
  1010bd:	50                   	push   eax
  1010be:	6a 15                	push   0x15
  1010c0:	e8 a6 02 00 00       	call   10136b <idt_set_gate>
  1010c5:	83 c4 10             	add    esp,0x10
  1010c8:	c7 c0 0e 01 10 00    	mov    eax,0x10010e
  1010ce:	68 8e 00 00 00       	push   0x8e
  1010d3:	6a 08                	push   0x8
  1010d5:	50                   	push   eax
  1010d6:	6a 16                	push   0x16
  1010d8:	e8 8e 02 00 00       	call   10136b <idt_set_gate>
  1010dd:	83 c4 10             	add    esp,0x10
  1010e0:	c7 c0 15 01 10 00    	mov    eax,0x100115
  1010e6:	68 8e 00 00 00       	push   0x8e
  1010eb:	6a 08                	push   0x8
  1010ed:	50                   	push   eax
  1010ee:	6a 17                	push   0x17
  1010f0:	e8 76 02 00 00       	call   10136b <idt_set_gate>
  1010f5:	83 c4 10             	add    esp,0x10
  1010f8:	c7 c0 1c 01 10 00    	mov    eax,0x10011c
  1010fe:	68 8e 00 00 00       	push   0x8e
  101103:	6a 08                	push   0x8
  101105:	50                   	push   eax
  101106:	6a 18                	push   0x18
  101108:	e8 5e 02 00 00       	call   10136b <idt_set_gate>
  10110d:	83 c4 10             	add    esp,0x10
  101110:	c7 c0 23 01 10 00    	mov    eax,0x100123
  101116:	68 8e 00 00 00       	push   0x8e
  10111b:	6a 08                	push   0x8
  10111d:	50                   	push   eax
  10111e:	6a 19                	push   0x19
  101120:	e8 46 02 00 00       	call   10136b <idt_set_gate>
  101125:	83 c4 10             	add    esp,0x10
  101128:	c7 c0 2a 01 10 00    	mov    eax,0x10012a
  10112e:	68 8e 00 00 00       	push   0x8e
  101133:	6a 08                	push   0x8
  101135:	50                   	push   eax
  101136:	6a 1a                	push   0x1a
  101138:	e8 2e 02 00 00       	call   10136b <idt_set_gate>
  10113d:	83 c4 10             	add    esp,0x10
  101140:	c7 c0 31 01 10 00    	mov    eax,0x100131
  101146:	68 8e 00 00 00       	push   0x8e
  10114b:	6a 08                	push   0x8
  10114d:	50                   	push   eax
  10114e:	6a 1b                	push   0x1b
  101150:	e8 16 02 00 00       	call   10136b <idt_set_gate>
  101155:	83 c4 10             	add    esp,0x10
  101158:	c7 c0 38 01 10 00    	mov    eax,0x100138
  10115e:	68 8e 00 00 00       	push   0x8e
  101163:	6a 08                	push   0x8
  101165:	50                   	push   eax
  101166:	6a 1c                	push   0x1c
  101168:	e8 fe 01 00 00       	call   10136b <idt_set_gate>
  10116d:	83 c4 10             	add    esp,0x10
  101170:	c7 c0 3f 01 10 00    	mov    eax,0x10013f
  101176:	68 8e 00 00 00       	push   0x8e
  10117b:	6a 08                	push   0x8
  10117d:	50                   	push   eax
  10117e:	6a 1d                	push   0x1d
  101180:	e8 e6 01 00 00       	call   10136b <idt_set_gate>
  101185:	83 c4 10             	add    esp,0x10
  101188:	c7 c0 46 01 10 00    	mov    eax,0x100146
  10118e:	68 8e 00 00 00       	push   0x8e
  101193:	6a 08                	push   0x8
  101195:	50                   	push   eax
  101196:	6a 1e                	push   0x1e
  101198:	e8 ce 01 00 00       	call   10136b <idt_set_gate>
  10119d:	83 c4 10             	add    esp,0x10
  1011a0:	c7 c0 4d 01 10 00    	mov    eax,0x10014d
  1011a6:	68 8e 00 00 00       	push   0x8e
  1011ab:	6a 08                	push   0x8
  1011ad:	50                   	push   eax
  1011ae:	6a 1f                	push   0x1f
  1011b0:	e8 b6 01 00 00       	call   10136b <idt_set_gate>
  1011b5:	83 c4 10             	add    esp,0x10
  1011b8:	c7 c0 8a 01 10 00    	mov    eax,0x10018a
  1011be:	68 8e 00 00 00       	push   0x8e
  1011c3:	6a 08                	push   0x8
  1011c5:	50                   	push   eax
  1011c6:	6a 20                	push   0x20
  1011c8:	e8 9e 01 00 00       	call   10136b <idt_set_gate>
  1011cd:	83 c4 10             	add    esp,0x10
  1011d0:	c7 c0 91 01 10 00    	mov    eax,0x100191
  1011d6:	68 8e 00 00 00       	push   0x8e
  1011db:	6a 08                	push   0x8
  1011dd:	50                   	push   eax
  1011de:	6a 21                	push   0x21
  1011e0:	e8 86 01 00 00       	call   10136b <idt_set_gate>
  1011e5:	83 c4 10             	add    esp,0x10
  1011e8:	c7 c0 98 01 10 00    	mov    eax,0x100198
  1011ee:	68 8e 00 00 00       	push   0x8e
  1011f3:	6a 08                	push   0x8
  1011f5:	50                   	push   eax
  1011f6:	6a 22                	push   0x22
  1011f8:	e8 6e 01 00 00       	call   10136b <idt_set_gate>
  1011fd:	83 c4 10             	add    esp,0x10
  101200:	c7 c0 9f 01 10 00    	mov    eax,0x10019f
  101206:	68 8e 00 00 00       	push   0x8e
  10120b:	6a 08                	push   0x8
  10120d:	50                   	push   eax
  10120e:	6a 23                	push   0x23
  101210:	e8 56 01 00 00       	call   10136b <idt_set_gate>
  101215:	83 c4 10             	add    esp,0x10
  101218:	c7 c0 a6 01 10 00    	mov    eax,0x1001a6
  10121e:	68 8e 00 00 00       	push   0x8e
  101223:	6a 08                	push   0x8
  101225:	50                   	push   eax
  101226:	6a 24                	push   0x24
  101228:	e8 3e 01 00 00       	call   10136b <idt_set_gate>
  10122d:	83 c4 10             	add    esp,0x10
  101230:	c7 c0 ad 01 10 00    	mov    eax,0x1001ad
  101236:	68 8e 00 00 00       	push   0x8e
  10123b:	6a 08                	push   0x8
  10123d:	50                   	push   eax
  10123e:	6a 25                	push   0x25
  101240:	e8 26 01 00 00       	call   10136b <idt_set_gate>
  101245:	83 c4 10             	add    esp,0x10
  101248:	c7 c0 b4 01 10 00    	mov    eax,0x1001b4
  10124e:	68 8e 00 00 00       	push   0x8e
  101253:	6a 08                	push   0x8
  101255:	50                   	push   eax
  101256:	6a 26                	push   0x26
  101258:	e8 0e 01 00 00       	call   10136b <idt_set_gate>
  10125d:	83 c4 10             	add    esp,0x10
  101260:	c7 c0 bb 01 10 00    	mov    eax,0x1001bb
  101266:	68 8e 00 00 00       	push   0x8e
  10126b:	6a 08                	push   0x8
  10126d:	50                   	push   eax
  10126e:	6a 27                	push   0x27
  101270:	e8 f6 00 00 00       	call   10136b <idt_set_gate>
  101275:	83 c4 10             	add    esp,0x10
  101278:	c7 c0 c2 01 10 00    	mov    eax,0x1001c2
  10127e:	68 8e 00 00 00       	push   0x8e
  101283:	6a 08                	push   0x8
  101285:	50                   	push   eax
  101286:	6a 28                	push   0x28
  101288:	e8 de 00 00 00       	call   10136b <idt_set_gate>
  10128d:	83 c4 10             	add    esp,0x10
  101290:	c7 c0 c9 01 10 00    	mov    eax,0x1001c9
  101296:	68 8e 00 00 00       	push   0x8e
  10129b:	6a 08                	push   0x8
  10129d:	50                   	push   eax
  10129e:	6a 29                	push   0x29
  1012a0:	e8 c6 00 00 00       	call   10136b <idt_set_gate>
  1012a5:	83 c4 10             	add    esp,0x10
  1012a8:	c7 c0 d0 01 10 00    	mov    eax,0x1001d0
  1012ae:	68 8e 00 00 00       	push   0x8e
  1012b3:	6a 08                	push   0x8
  1012b5:	50                   	push   eax
  1012b6:	6a 2a                	push   0x2a
  1012b8:	e8 ae 00 00 00       	call   10136b <idt_set_gate>
  1012bd:	83 c4 10             	add    esp,0x10
  1012c0:	c7 c0 d7 01 10 00    	mov    eax,0x1001d7
  1012c6:	68 8e 00 00 00       	push   0x8e
  1012cb:	6a 08                	push   0x8
  1012cd:	50                   	push   eax
  1012ce:	6a 2b                	push   0x2b
  1012d0:	e8 96 00 00 00       	call   10136b <idt_set_gate>
  1012d5:	83 c4 10             	add    esp,0x10
  1012d8:	c7 c0 de 01 10 00    	mov    eax,0x1001de
  1012de:	68 8e 00 00 00       	push   0x8e
  1012e3:	6a 08                	push   0x8
  1012e5:	50                   	push   eax
  1012e6:	6a 2c                	push   0x2c
  1012e8:	e8 7e 00 00 00       	call   10136b <idt_set_gate>
  1012ed:	83 c4 10             	add    esp,0x10
  1012f0:	c7 c0 e5 01 10 00    	mov    eax,0x1001e5
  1012f6:	68 8e 00 00 00       	push   0x8e
  1012fb:	6a 08                	push   0x8
  1012fd:	50                   	push   eax
  1012fe:	6a 2d                	push   0x2d
  101300:	e8 66 00 00 00       	call   10136b <idt_set_gate>
  101305:	83 c4 10             	add    esp,0x10
  101308:	c7 c0 ec 01 10 00    	mov    eax,0x1001ec
  10130e:	68 8e 00 00 00       	push   0x8e
  101313:	6a 08                	push   0x8
  101315:	50                   	push   eax
  101316:	6a 2e                	push   0x2e
  101318:	e8 4e 00 00 00       	call   10136b <idt_set_gate>
  10131d:	83 c4 10             	add    esp,0x10
  101320:	c7 c0 f3 01 10 00    	mov    eax,0x1001f3
  101326:	68 8e 00 00 00       	push   0x8e
  10132b:	6a 08                	push   0x8
  10132d:	50                   	push   eax
  10132e:	6a 2f                	push   0x2f
  101330:	e8 36 00 00 00       	call   10136b <idt_set_gate>
  101335:	83 c4 10             	add    esp,0x10
  101338:	c7 c0 54 01 10 00    	mov    eax,0x100154
  10133e:	68 8e 00 00 00       	push   0x8e
  101343:	6a 08                	push   0x8
  101345:	50                   	push   eax
  101346:	68 ff 00 00 00       	push   0xff
  10134b:	e8 1b 00 00 00       	call   10136b <idt_set_gate>
  101350:	83 c4 10             	add    esp,0x10
  101353:	c7 c0 40 d0 18 00    	mov    eax,0x18d040
  101359:	83 ec 0c             	sub    esp,0xc
  10135c:	50                   	push   eax
  10135d:	e8 ee ec ff ff       	call   100050 <idt_flush>
  101362:	83 c4 10             	add    esp,0x10
  101365:	90                   	nop
  101366:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101369:	c9                   	leave  
  10136a:	c3                   	ret    

0010136b <idt_set_gate>:
  10136b:	f3 0f 1e fb          	endbr32 
  10136f:	55                   	push   ebp
  101370:	89 e5                	mov    ebp,esp
  101372:	53                   	push   ebx
  101373:	83 ec 0c             	sub    esp,0xc
  101376:	e8 85 1c 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  10137b:	05 85 2c 00 00       	add    eax,0x2c85
  101380:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  101383:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  101386:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  101389:	88 5d f8             	mov    BYTE PTR [ebp-0x8],bl
  10138c:	66 89 55 f4          	mov    WORD PTR [ebp-0xc],dx
  101390:	89 ca                	mov    edx,ecx
  101392:	88 55 f0             	mov    BYTE PTR [ebp-0x10],dl
  101395:	0f b6 4d f8          	movzx  ecx,BYTE PTR [ebp-0x8]
  101399:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  10139c:	89 d3                	mov    ebx,edx
  10139e:	c7 c2 60 d0 18 00    	mov    edx,0x18d060
  1013a4:	66 89 1c ca          	mov    WORD PTR [edx+ecx*8],bx
  1013a8:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  1013ab:	c1 ea 10             	shr    edx,0x10
  1013ae:	0f b6 4d f8          	movzx  ecx,BYTE PTR [ebp-0x8]
  1013b2:	89 d3                	mov    ebx,edx
  1013b4:	c7 c2 60 d0 18 00    	mov    edx,0x18d060
  1013ba:	66 89 5c ca 06       	mov    WORD PTR [edx+ecx*8+0x6],bx
  1013bf:	0f b6 4d f8          	movzx  ecx,BYTE PTR [ebp-0x8]
  1013c3:	c7 c2 60 d0 18 00    	mov    edx,0x18d060
  1013c9:	0f b7 5d f4          	movzx  ebx,WORD PTR [ebp-0xc]
  1013cd:	66 89 5c ca 02       	mov    WORD PTR [edx+ecx*8+0x2],bx
  1013d2:	0f b6 4d f8          	movzx  ecx,BYTE PTR [ebp-0x8]
  1013d6:	c7 c2 60 d0 18 00    	mov    edx,0x18d060
  1013dc:	c6 44 ca 04 00       	mov    BYTE PTR [edx+ecx*8+0x4],0x0
  1013e1:	0f b6 55 f8          	movzx  edx,BYTE PTR [ebp-0x8]
  1013e5:	c7 c0 60 d0 18 00    	mov    eax,0x18d060
  1013eb:	0f b6 4d f0          	movzx  ecx,BYTE PTR [ebp-0x10]
  1013ef:	88 4c d0 05          	mov    BYTE PTR [eax+edx*8+0x5],cl
  1013f3:	90                   	nop
  1013f4:	83 c4 0c             	add    esp,0xc
  1013f7:	5b                   	pop    ebx
  1013f8:	5d                   	pop    ebp
  1013f9:	c3                   	ret    

001013fa <isr_handler>:
  1013fa:	f3 0f 1e fb          	endbr32 
  1013fe:	55                   	push   ebp
  1013ff:	89 e5                	mov    ebp,esp
  101401:	53                   	push   ebx
  101402:	83 ec 04             	sub    esp,0x4
  101405:	e8 f6 1b 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  10140a:	05 f6 2b 00 00       	add    eax,0x2bf6
  10140f:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101412:	8b 4a 24             	mov    ecx,DWORD PTR [edx+0x24]
  101415:	c7 c2 60 d8 18 00    	mov    edx,0x18d860
  10141b:	8b 14 8a             	mov    edx,DWORD PTR [edx+ecx*4]
  10141e:	85 d2                	test   edx,edx
  101420:	74 1c                	je     10143e <isr_handler+0x44>
  101422:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101425:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  101428:	c7 c0 60 d8 18 00    	mov    eax,0x18d860
  10142e:	8b 04 90             	mov    eax,DWORD PTR [eax+edx*4]
  101431:	83 ec 0c             	sub    esp,0xc
  101434:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  101437:	ff d0                	call   eax
  101439:	83 c4 10             	add    esp,0x10
  10143c:	eb 1c                	jmp    10145a <isr_handler+0x60>
  10143e:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101441:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  101444:	52                   	push   edx
  101445:	8d 90 a4 f1 ff ff    	lea    edx,[eax-0xe5c]
  10144b:	52                   	push   edx
  10144c:	6a 0a                	push   0xa
  10144e:	6a 00                	push   0x0
  101450:	89 c3                	mov    ebx,eax
  101452:	e8 03 f2 ff ff       	call   10065a <printk_color>
  101457:	83 c4 10             	add    esp,0x10
  10145a:	90                   	nop
  10145b:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  10145e:	c9                   	leave  
  10145f:	c3                   	ret    

00101460 <register_interrupt_handler>:
  101460:	f3 0f 1e fb          	endbr32 
  101464:	55                   	push   ebp
  101465:	89 e5                	mov    ebp,esp
  101467:	83 ec 04             	sub    esp,0x4
  10146a:	e8 91 1b 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  10146f:	05 91 2b 00 00       	add    eax,0x2b91
  101474:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101477:	88 55 fc             	mov    BYTE PTR [ebp-0x4],dl
  10147a:	0f b6 55 fc          	movzx  edx,BYTE PTR [ebp-0x4]
  10147e:	c7 c0 60 d8 18 00    	mov    eax,0x18d860
  101484:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  101487:	89 0c 90             	mov    DWORD PTR [eax+edx*4],ecx
  10148a:	90                   	nop
  10148b:	c9                   	leave  
  10148c:	c3                   	ret    

0010148d <irq_handler>:
  10148d:	f3 0f 1e fb          	endbr32 
  101491:	55                   	push   ebp
  101492:	89 e5                	mov    ebp,esp
  101494:	53                   	push   ebx
  101495:	83 ec 04             	sub    esp,0x4
  101498:	e8 67 1b 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  10149d:	81 c3 63 2b 00 00    	add    ebx,0x2b63
  1014a3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1014a6:	8b 40 24             	mov    eax,DWORD PTR [eax+0x24]
  1014a9:	83 f8 27             	cmp    eax,0x27
  1014ac:	76 12                	jbe    1014c0 <irq_handler+0x33>
  1014ae:	83 ec 08             	sub    esp,0x8
  1014b1:	6a 20                	push   0x20
  1014b3:	68 a0 00 00 00       	push   0xa0
  1014b8:	e8 bd 04 00 00       	call   10197a <outb>
  1014bd:	83 c4 10             	add    esp,0x10
  1014c0:	83 ec 08             	sub    esp,0x8
  1014c3:	6a 20                	push   0x20
  1014c5:	6a 20                	push   0x20
  1014c7:	e8 ae 04 00 00       	call   10197a <outb>
  1014cc:	83 c4 10             	add    esp,0x10
  1014cf:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1014d2:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  1014d5:	c7 c0 60 d8 18 00    	mov    eax,0x18d860
  1014db:	8b 04 90             	mov    eax,DWORD PTR [eax+edx*4]
  1014de:	85 c0                	test   eax,eax
  1014e0:	74 1a                	je     1014fc <irq_handler+0x6f>
  1014e2:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1014e5:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  1014e8:	c7 c0 60 d8 18 00    	mov    eax,0x18d860
  1014ee:	8b 04 90             	mov    eax,DWORD PTR [eax+edx*4]
  1014f1:	83 ec 0c             	sub    esp,0xc
  1014f4:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  1014f7:	ff d0                	call   eax
  1014f9:	83 c4 10             	add    esp,0x10
  1014fc:	90                   	nop
  1014fd:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101500:	c9                   	leave  
  101501:	c3                   	ret    

00101502 <show_memory_map>:
  101502:	f3 0f 1e fb          	endbr32 
  101506:	55                   	push   ebp
  101507:	89 e5                	mov    ebp,esp
  101509:	57                   	push   edi
  10150a:	56                   	push   esi
  10150b:	53                   	push   ebx
  10150c:	83 ec 1c             	sub    esp,0x1c
  10150f:	e8 f0 1a 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  101514:	81 c3 ec 2a 00 00    	add    ebx,0x2aec
  10151a:	c7 c0 20 c0 10 00    	mov    eax,0x10c020
  101520:	8b 00                	mov    eax,DWORD PTR [eax]
  101522:	8b 40 30             	mov    eax,DWORD PTR [eax+0x30]
  101525:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  101528:	c7 c0 20 c0 10 00    	mov    eax,0x10c020
  10152e:	8b 00                	mov    eax,DWORD PTR [eax]
  101530:	8b 40 2c             	mov    eax,DWORD PTR [eax+0x2c]
  101533:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  101536:	83 ec 0c             	sub    esp,0xc
  101539:	8d 83 c0 f1 ff ff    	lea    eax,[ebx-0xe40]
  10153f:	50                   	push   eax
  101540:	e8 b7 f0 ff ff       	call   1005fc <printk>
  101545:	83 c4 10             	add    esp,0x10
  101548:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  10154b:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  10154e:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  101551:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  101554:	eb 39                	jmp    10158f <show_memory_map+0x8d>
  101556:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  101559:	8b 78 14             	mov    edi,DWORD PTR [eax+0x14]
  10155c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  10155f:	8b 70 0c             	mov    esi,DWORD PTR [eax+0xc]
  101562:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  101565:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  101568:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  10156b:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  10156e:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  101571:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  101574:	83 ec 08             	sub    esp,0x8
  101577:	57                   	push   edi
  101578:	56                   	push   esi
  101579:	51                   	push   ecx
  10157a:	52                   	push   edx
  10157b:	50                   	push   eax
  10157c:	8d 83 d0 f1 ff ff    	lea    eax,[ebx-0xe30]
  101582:	50                   	push   eax
  101583:	e8 74 f0 ff ff       	call   1005fc <printk>
  101588:	83 c4 20             	add    esp,0x20
  10158b:	83 45 e4 18          	add    DWORD PTR [ebp-0x1c],0x18
  10158f:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  101592:	8b 45 dc             	mov    eax,DWORD PTR [ebp-0x24]
  101595:	01 c2                	add    edx,eax
  101597:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  10159a:	39 c2                	cmp    edx,eax
  10159c:	77 b8                	ja     101556 <show_memory_map+0x54>
  10159e:	90                   	nop
  10159f:	90                   	nop
  1015a0:	8d 65 f4             	lea    esp,[ebp-0xc]
  1015a3:	5b                   	pop    ebx
  1015a4:	5e                   	pop    esi
  1015a5:	5f                   	pop    edi
  1015a6:	5d                   	pop    ebp
  1015a7:	c3                   	ret    

001015a8 <init_pmm>:
  1015a8:	f3 0f 1e fb          	endbr32 
  1015ac:	55                   	push   ebp
  1015ad:	89 e5                	mov    ebp,esp
  1015af:	53                   	push   ebx
  1015b0:	83 ec 24             	sub    esp,0x24
  1015b3:	e8 4c 1a 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  1015b8:	81 c3 48 2a 00 00    	add    ebx,0x2a48
  1015be:	c7 c0 20 c0 10 00    	mov    eax,0x10c020
  1015c4:	8b 00                	mov    eax,DWORD PTR [eax]
  1015c6:	8b 40 30             	mov    eax,DWORD PTR [eax+0x30]
  1015c9:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  1015cc:	c7 c0 20 c0 10 00    	mov    eax,0x10c020
  1015d2:	8b 00                	mov    eax,DWORD PTR [eax]
  1015d4:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  1015d7:	89 d0                	mov    eax,edx
  1015d9:	01 c0                	add    eax,eax
  1015db:	01 d0                	add    eax,edx
  1015dd:	c1 e0 03             	shl    eax,0x3
  1015e0:	89 c2                	mov    edx,eax
  1015e2:	c7 c0 20 c0 10 00    	mov    eax,0x10c020
  1015e8:	8b 00                	mov    eax,DWORD PTR [eax]
  1015ea:	8b 40 30             	mov    eax,DWORD PTR [eax+0x30]
  1015ed:	01 d0                	add    eax,edx
  1015ef:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  1015f2:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  1015f5:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  1015f8:	e9 85 00 00 00       	jmp    101682 <init_pmm+0xda>
  1015fd:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101600:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  101603:	83 f8 01             	cmp    eax,0x1
  101606:	75 76                	jne    10167e <init_pmm+0xd6>
  101608:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10160b:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  10160e:	3d 00 00 10 00       	cmp    eax,0x100000
  101613:	75 69                	jne    10167e <init_pmm+0xd6>
  101615:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101618:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  10161b:	c7 c2 00 50 19 00    	mov    edx,0x195000
  101621:	89 d1                	mov    ecx,edx
  101623:	c7 c2 00 00 10 00    	mov    edx,0x100000
  101629:	29 d1                	sub    ecx,edx
  10162b:	89 ca                	mov    edx,ecx
  10162d:	01 d0                	add    eax,edx
  10162f:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  101632:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101635:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  101638:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10163b:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  10163e:	01 d0                	add    eax,edx
  101640:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  101643:	eb 28                	jmp    10166d <init_pmm+0xc5>
  101645:	83 ec 0c             	sub    esp,0xc
  101648:	ff 75 f0             	push   DWORD PTR [ebp-0x10]
  10164b:	e8 98 00 00 00       	call   1016e8 <pmm_free_page>
  101650:	83 c4 10             	add    esp,0x10
  101653:	81 45 f0 00 10 00 00 	add    DWORD PTR [ebp-0x10],0x1000
  10165a:	c7 c0 60 dc 18 00    	mov    eax,0x18dc60
  101660:	8b 00                	mov    eax,DWORD PTR [eax]
  101662:	8d 50 01             	lea    edx,[eax+0x1]
  101665:	c7 c0 60 dc 18 00    	mov    eax,0x18dc60
  10166b:	89 10                	mov    DWORD PTR [eax],edx
  10166d:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  101670:	3b 45 e4             	cmp    eax,DWORD PTR [ebp-0x1c]
  101673:	73 09                	jae    10167e <init_pmm+0xd6>
  101675:	81 7d f0 00 00 00 20 	cmp    DWORD PTR [ebp-0x10],0x20000000
  10167c:	76 c7                	jbe    101645 <init_pmm+0x9d>
  10167e:	83 45 f4 18          	add    DWORD PTR [ebp-0xc],0x18
  101682:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101685:	3b 45 e8             	cmp    eax,DWORD PTR [ebp-0x18]
  101688:	0f 82 6f ff ff ff    	jb     1015fd <init_pmm+0x55>
  10168e:	90                   	nop
  10168f:	90                   	nop
  101690:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101693:	c9                   	leave  
  101694:	c3                   	ret    

00101695 <pmm_alloc_page>:
  101695:	f3 0f 1e fb          	endbr32 
  101699:	55                   	push   ebp
  10169a:	89 e5                	mov    ebp,esp
  10169c:	53                   	push   ebx
  10169d:	83 ec 14             	sub    esp,0x14
  1016a0:	e8 5f 19 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  1016a5:	81 c3 5b 29 00 00    	add    ebx,0x295b
  1016ab:	8b 83 44 88 08 00    	mov    eax,DWORD PTR [ebx+0x88844]
  1016b1:	85 c0                	test   eax,eax
  1016b3:	75 12                	jne    1016c7 <pmm_alloc_page+0x32>
  1016b5:	83 ec 0c             	sub    esp,0xc
  1016b8:	8d 83 05 f2 ff ff    	lea    eax,[ebx-0xdfb]
  1016be:	50                   	push   eax
  1016bf:	e8 2e ee ff ff       	call   1004f2 <panic>
  1016c4:	83 c4 10             	add    esp,0x10
  1016c7:	8b 83 44 88 08 00    	mov    eax,DWORD PTR [ebx+0x88844]
  1016cd:	8d 50 ff             	lea    edx,[eax-0x1]
  1016d0:	89 93 44 88 08 00    	mov    DWORD PTR [ebx+0x88844],edx
  1016d6:	8b 84 83 40 88 00 00 	mov    eax,DWORD PTR [ebx+eax*4+0x8840]
  1016dd:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  1016e0:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  1016e3:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  1016e6:	c9                   	leave  
  1016e7:	c3                   	ret    

001016e8 <pmm_free_page>:
  1016e8:	f3 0f 1e fb          	endbr32 
  1016ec:	55                   	push   ebp
  1016ed:	89 e5                	mov    ebp,esp
  1016ef:	53                   	push   ebx
  1016f0:	83 ec 04             	sub    esp,0x4
  1016f3:	e8 0c 19 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  1016f8:	81 c3 08 29 00 00    	add    ebx,0x2908
  1016fe:	8b 83 44 88 08 00    	mov    eax,DWORD PTR [ebx+0x88844]
  101704:	3d 00 00 02 00       	cmp    eax,0x20000
  101709:	75 12                	jne    10171d <pmm_free_page+0x35>
  10170b:	83 ec 0c             	sub    esp,0xc
  10170e:	8d 83 13 f2 ff ff    	lea    eax,[ebx-0xded]
  101714:	50                   	push   eax
  101715:	e8 d8 ed ff ff       	call   1004f2 <panic>
  10171a:	83 c4 10             	add    esp,0x10
  10171d:	8b 83 44 88 08 00    	mov    eax,DWORD PTR [ebx+0x88844]
  101723:	83 c0 01             	add    eax,0x1
  101726:	89 83 44 88 08 00    	mov    DWORD PTR [ebx+0x88844],eax
  10172c:	8b 83 44 88 08 00    	mov    eax,DWORD PTR [ebx+0x88844]
  101732:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101735:	89 94 83 40 88 00 00 	mov    DWORD PTR [ebx+eax*4+0x8840],edx
  10173c:	90                   	nop
  10173d:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101740:	c9                   	leave  
  101741:	c3                   	ret    

00101742 <strcmp>:
  101742:	55                   	push   ebp
  101743:	89 e5                	mov    ebp,esp
  101745:	e8 b6 18 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  10174a:	05 b6 28 00 00       	add    eax,0x28b6
  10174f:	eb 08                	jmp    101759 <strcmp+0x17>
  101751:	83 45 08 01          	add    DWORD PTR [ebp+0x8],0x1
  101755:	83 45 0c 01          	add    DWORD PTR [ebp+0xc],0x1
  101759:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  10175c:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  10175f:	84 c0                	test   al,al
  101761:	74 1a                	je     10177d <strcmp+0x3b>
  101763:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101766:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101769:	84 c0                	test   al,al
  10176b:	74 10                	je     10177d <strcmp+0x3b>
  10176d:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101770:	0f b6 10             	movzx  edx,BYTE PTR [eax]
  101773:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101776:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101779:	38 c2                	cmp    dl,al
  10177b:	74 d4                	je     101751 <strcmp+0xf>
  10177d:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101780:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101783:	0f be d0             	movsx  edx,al
  101786:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101789:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  10178c:	0f be c0             	movsx  eax,al
  10178f:	29 c2                	sub    edx,eax
  101791:	89 d0                	mov    eax,edx
  101793:	5d                   	pop    ebp
  101794:	c3                   	ret    

00101795 <elf_from_multiboot>:
  101795:	f3 0f 1e fb          	endbr32 
  101799:	55                   	push   ebp
  10179a:	89 e5                	mov    ebp,esp
  10179c:	53                   	push   ebx
  10179d:	83 ec 20             	sub    esp,0x20
  1017a0:	e8 5f 18 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  1017a5:	81 c3 5b 28 00 00    	add    ebx,0x285b
  1017ab:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  1017ae:	8b 40 24             	mov    eax,DWORD PTR [eax+0x24]
  1017b1:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  1017b4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  1017b7:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  1017ba:	89 d0                	mov    eax,edx
  1017bc:	c1 e0 02             	shl    eax,0x2
  1017bf:	01 d0                	add    eax,edx
  1017c1:	c1 e0 03             	shl    eax,0x3
  1017c4:	89 c2                	mov    edx,eax
  1017c6:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  1017c9:	01 d0                	add    eax,edx
  1017cb:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  1017ce:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  1017d1:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [ebp-0x8],0x0
  1017d8:	e9 b6 00 00 00       	jmp    101893 <elf_from_multiboot+0xfe>
  1017dd:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  1017e0:	89 d0                	mov    eax,edx
  1017e2:	c1 e0 02             	shl    eax,0x2
  1017e5:	01 d0                	add    eax,edx
  1017e7:	c1 e0 03             	shl    eax,0x3
  1017ea:	89 c2                	mov    edx,eax
  1017ec:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  1017ef:	01 d0                	add    eax,edx
  1017f1:	8b 10                	mov    edx,DWORD PTR [eax]
  1017f3:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  1017f6:	01 d0                	add    eax,edx
  1017f8:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  1017fb:	8d 83 2a f2 ff ff    	lea    eax,[ebx-0xdd6]
  101801:	50                   	push   eax
  101802:	ff 75 ec             	push   DWORD PTR [ebp-0x14]
  101805:	e8 38 ff ff ff       	call   101742 <strcmp>
  10180a:	83 c4 08             	add    esp,0x8
  10180d:	85 c0                	test   eax,eax
  10180f:	75 34                	jne    101845 <elf_from_multiboot+0xb0>
  101811:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  101814:	89 d0                	mov    eax,edx
  101816:	c1 e0 02             	shl    eax,0x2
  101819:	01 d0                	add    eax,edx
  10181b:	c1 e0 03             	shl    eax,0x3
  10181e:	89 c2                	mov    edx,eax
  101820:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101823:	01 d0                	add    eax,edx
  101825:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  101828:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  10182b:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  10182e:	89 d0                	mov    eax,edx
  101830:	c1 e0 02             	shl    eax,0x2
  101833:	01 d0                	add    eax,edx
  101835:	c1 e0 03             	shl    eax,0x3
  101838:	89 c2                	mov    edx,eax
  10183a:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10183d:	01 d0                	add    eax,edx
  10183f:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  101842:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  101845:	8d 83 32 f2 ff ff    	lea    eax,[ebx-0xdce]
  10184b:	50                   	push   eax
  10184c:	ff 75 ec             	push   DWORD PTR [ebp-0x14]
  10184f:	e8 ee fe ff ff       	call   101742 <strcmp>
  101854:	83 c4 08             	add    esp,0x8
  101857:	85 c0                	test   eax,eax
  101859:	75 34                	jne    10188f <elf_from_multiboot+0xfa>
  10185b:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  10185e:	89 d0                	mov    eax,edx
  101860:	c1 e0 02             	shl    eax,0x2
  101863:	01 d0                	add    eax,edx
  101865:	c1 e0 03             	shl    eax,0x3
  101868:	89 c2                	mov    edx,eax
  10186a:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  10186d:	01 d0                	add    eax,edx
  10186f:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  101872:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  101875:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  101878:	89 d0                	mov    eax,edx
  10187a:	c1 e0 02             	shl    eax,0x2
  10187d:	01 d0                	add    eax,edx
  10187f:	c1 e0 03             	shl    eax,0x3
  101882:	89 c2                	mov    edx,eax
  101884:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101887:	01 d0                	add    eax,edx
  101889:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  10188c:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  10188f:	83 45 f8 01          	add    DWORD PTR [ebp-0x8],0x1
  101893:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101896:	8b 50 1c             	mov    edx,DWORD PTR [eax+0x1c]
  101899:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  10189c:	39 c2                	cmp    edx,eax
  10189e:	0f 87 39 ff ff ff    	ja     1017dd <elf_from_multiboot+0x48>
  1018a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1018a7:	8b 55 dc             	mov    edx,DWORD PTR [ebp-0x24]
  1018aa:	89 10                	mov    DWORD PTR [eax],edx
  1018ac:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  1018af:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  1018b2:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  1018b5:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  1018b8:	8b 55 e8             	mov    edx,DWORD PTR [ebp-0x18]
  1018bb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  1018be:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1018c1:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  1018c4:	c9                   	leave  
  1018c5:	c2 04 00             	ret    0x4

001018c8 <elf_lookup_symbol>:
  1018c8:	f3 0f 1e fb          	endbr32 
  1018cc:	55                   	push   ebp
  1018cd:	89 e5                	mov    ebp,esp
  1018cf:	83 ec 10             	sub    esp,0x10
  1018d2:	e8 29 17 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  1018d7:	05 29 27 00 00       	add    eax,0x2729
  1018dc:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  1018e3:	eb 78                	jmp    10195d <elf_lookup_symbol+0x95>
  1018e5:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  1018e8:	8b 00                	mov    eax,DWORD PTR [eax]
  1018ea:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  1018ed:	c1 e2 04             	shl    edx,0x4
  1018f0:	01 d0                	add    eax,edx
  1018f2:	0f b6 40 0c          	movzx  eax,BYTE PTR [eax+0xc]
  1018f6:	0f b6 c0             	movzx  eax,al
  1018f9:	83 e0 0f             	and    eax,0xf
  1018fc:	83 f8 02             	cmp    eax,0x2
  1018ff:	75 57                	jne    101958 <elf_lookup_symbol+0x90>
  101901:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101904:	8b 00                	mov    eax,DWORD PTR [eax]
  101906:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  101909:	c1 e2 04             	shl    edx,0x4
  10190c:	01 d0                	add    eax,edx
  10190e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  101911:	39 45 08             	cmp    DWORD PTR [ebp+0x8],eax
  101914:	72 43                	jb     101959 <elf_lookup_symbol+0x91>
  101916:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101919:	8b 00                	mov    eax,DWORD PTR [eax]
  10191b:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  10191e:	c1 e2 04             	shl    edx,0x4
  101921:	01 d0                	add    eax,edx
  101923:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  101926:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101929:	8b 00                	mov    eax,DWORD PTR [eax]
  10192b:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  10192e:	c1 e1 04             	shl    ecx,0x4
  101931:	01 c8                	add    eax,ecx
  101933:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  101936:	01 d0                	add    eax,edx
  101938:	39 45 08             	cmp    DWORD PTR [ebp+0x8],eax
  10193b:	73 1c                	jae    101959 <elf_lookup_symbol+0x91>
  10193d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101940:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  101943:	89 c1                	mov    ecx,eax
  101945:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101948:	8b 00                	mov    eax,DWORD PTR [eax]
  10194a:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  10194d:	c1 e2 04             	shl    edx,0x4
  101950:	01 d0                	add    eax,edx
  101952:	8b 00                	mov    eax,DWORD PTR [eax]
  101954:	01 c8                	add    eax,ecx
  101956:	eb 20                	jmp    101978 <elf_lookup_symbol+0xb0>
  101958:	90                   	nop
  101959:	83 45 fc 01          	add    DWORD PTR [ebp-0x4],0x1
  10195d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  101960:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  101963:	c1 e8 04             	shr    eax,0x4
  101966:	89 c2                	mov    edx,eax
  101968:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  10196b:	39 c2                	cmp    edx,eax
  10196d:	0f 87 72 ff ff ff    	ja     1018e5 <elf_lookup_symbol+0x1d>
  101973:	b8 00 00 00 00       	mov    eax,0x0
  101978:	c9                   	leave  
  101979:	c3                   	ret    

0010197a <outb>:
  10197a:	f3 0f 1e fb          	endbr32 
  10197e:	55                   	push   ebp
  10197f:	89 e5                	mov    ebp,esp
  101981:	83 ec 08             	sub    esp,0x8
  101984:	e8 77 16 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101989:	05 77 26 00 00       	add    eax,0x2677
  10198e:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101991:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  101994:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  101998:	89 d0                	mov    eax,edx
  10199a:	88 45 f8             	mov    BYTE PTR [ebp-0x8],al
  10199d:	0f b7 55 fc          	movzx  edx,WORD PTR [ebp-0x4]
  1019a1:	0f b6 45 f8          	movzx  eax,BYTE PTR [ebp-0x8]
  1019a5:	ee                   	out    dx,al
  1019a6:	90                   	nop
  1019a7:	c9                   	leave  
  1019a8:	c3                   	ret    

001019a9 <inb>:
  1019a9:	f3 0f 1e fb          	endbr32 
  1019ad:	55                   	push   ebp
  1019ae:	89 e5                	mov    ebp,esp
  1019b0:	83 ec 14             	sub    esp,0x14
  1019b3:	e8 48 16 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  1019b8:	05 48 26 00 00       	add    eax,0x2648
  1019bd:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1019c0:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  1019c4:	0f b7 45 ec          	movzx  eax,WORD PTR [ebp-0x14]
  1019c8:	89 c2                	mov    edx,eax
  1019ca:	ec                   	in     al,dx
  1019cb:	88 45 ff             	mov    BYTE PTR [ebp-0x1],al
  1019ce:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  1019d2:	c9                   	leave  
  1019d3:	c3                   	ret    

001019d4 <inw>:
  1019d4:	f3 0f 1e fb          	endbr32 
  1019d8:	55                   	push   ebp
  1019d9:	89 e5                	mov    ebp,esp
  1019db:	83 ec 14             	sub    esp,0x14
  1019de:	e8 1d 16 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  1019e3:	05 1d 26 00 00       	add    eax,0x261d
  1019e8:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  1019eb:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  1019ef:	0f b7 45 ec          	movzx  eax,WORD PTR [ebp-0x14]
  1019f3:	89 c2                	mov    edx,eax
  1019f5:	66 ed                	in     ax,dx
  1019f7:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  1019fb:	0f b7 45 fe          	movzx  eax,WORD PTR [ebp-0x2]
  1019ff:	c9                   	leave  
  101a00:	c3                   	ret    

00101a01 <kern_entry>:
  101a01:	f3 0f 1e fb          	endbr32 
  101a05:	55                   	push   ebp
  101a06:	89 e5                	mov    ebp,esp
  101a08:	53                   	push   ebx
  101a09:	83 ec 14             	sub    esp,0x14
  101a0c:	e8 f3 15 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  101a11:	81 c3 ef 25 00 00    	add    ebx,0x25ef
  101a17:	e8 9d e9 ff ff       	call   1003b9 <init_debug>
  101a1c:	e8 05 e8 ff ff       	call   100226 <init_gdt>
  101a21:	e8 8d f3 ff ff       	call   100db3 <init_idt>
  101a26:	e8 ad 02 00 00       	call   101cd8 <console_clear>
  101a2b:	83 ec 04             	sub    esp,0x4
  101a2e:	8d 83 3c f2 ff ff    	lea    eax,[ebx-0xdc4]
  101a34:	50                   	push   eax
  101a35:	6a 02                	push   0x2
  101a37:	6a 00                	push   0x0
  101a39:	e8 1c ec ff ff       	call   10065a <printk_color>
  101a3e:	83 c4 10             	add    esp,0x10
  101a41:	83 ec 0c             	sub    esp,0xc
  101a44:	68 c8 00 00 00       	push   0xc8
  101a49:	e8 6e 01 00 00       	call   101bbc <init_timer>
  101a4e:	83 c4 10             	add    esp,0x10
  101a51:	fb                   	sti    
  101a52:	83 ec 08             	sub    esp,0x8
  101a55:	c7 c0 00 00 10 00    	mov    eax,0x100000
  101a5b:	50                   	push   eax
  101a5c:	8d 83 50 f2 ff ff    	lea    eax,[ebx-0xdb0]
  101a62:	50                   	push   eax
  101a63:	e8 94 eb ff ff       	call   1005fc <printk>
  101a68:	83 c4 10             	add    esp,0x10
  101a6b:	83 ec 08             	sub    esp,0x8
  101a6e:	c7 c0 00 50 19 00    	mov    eax,0x195000
  101a74:	50                   	push   eax
  101a75:	8d 83 70 f2 ff ff    	lea    eax,[ebx-0xd90]
  101a7b:	50                   	push   eax
  101a7c:	e8 7b eb ff ff       	call   1005fc <printk>
  101a81:	83 c4 10             	add    esp,0x10
  101a84:	c7 c0 00 50 19 00    	mov    eax,0x195000
  101a8a:	89 c2                	mov    edx,eax
  101a8c:	c7 c0 00 00 10 00    	mov    eax,0x100000
  101a92:	29 c2                	sub    edx,eax
  101a94:	89 d0                	mov    eax,edx
  101a96:	8d 90 ff 03 00 00    	lea    edx,[eax+0x3ff]
  101a9c:	85 c0                	test   eax,eax
  101a9e:	0f 48 c2             	cmovs  eax,edx
  101aa1:	c1 f8 0a             	sar    eax,0xa
  101aa4:	83 ec 08             	sub    esp,0x8
  101aa7:	50                   	push   eax
  101aa8:	8d 83 90 f2 ff ff    	lea    eax,[ebx-0xd70]
  101aae:	50                   	push   eax
  101aaf:	e8 48 eb ff ff       	call   1005fc <printk>
  101ab4:	83 c4 10             	add    esp,0x10
  101ab7:	e8 46 fa ff ff       	call   101502 <show_memory_map>
  101abc:	e8 e7 fa ff ff       	call   1015a8 <init_pmm>
  101ac1:	c7 c0 60 dc 18 00    	mov    eax,0x18dc60
  101ac7:	8b 00                	mov    eax,DWORD PTR [eax]
  101ac9:	50                   	push   eax
  101aca:	8d 83 b4 f2 ff ff    	lea    eax,[ebx-0xd4c]
  101ad0:	50                   	push   eax
  101ad1:	6a 04                	push   0x4
  101ad3:	6a 00                	push   0x0
  101ad5:	e8 80 eb ff ff       	call   10065a <printk_color>
  101ada:	83 c4 10             	add    esp,0x10
  101add:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  101ae4:	83 ec 04             	sub    esp,0x4
  101ae7:	8d 83 e0 f2 ff ff    	lea    eax,[ebx-0xd20]
  101aed:	50                   	push   eax
  101aee:	6a 0e                	push   0xe
  101af0:	6a 00                	push   0x0
  101af2:	e8 63 eb ff ff       	call   10065a <printk_color>
  101af7:	83 c4 10             	add    esp,0x10
  101afa:	e8 96 fb ff ff       	call   101695 <pmm_alloc_page>
  101aff:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  101b02:	ff 75 f4             	push   DWORD PTR [ebp-0xc]
  101b05:	8d 83 fe f2 ff ff    	lea    eax,[ebx-0xd02]
  101b0b:	50                   	push   eax
  101b0c:	6a 0e                	push   0xe
  101b0e:	6a 00                	push   0x0
  101b10:	e8 45 eb ff ff       	call   10065a <printk_color>
  101b15:	83 c4 10             	add    esp,0x10
  101b18:	e8 78 fb ff ff       	call   101695 <pmm_alloc_page>
  101b1d:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  101b20:	ff 75 f4             	push   DWORD PTR [ebp-0xc]
  101b23:	8d 83 fe f2 ff ff    	lea    eax,[ebx-0xd02]
  101b29:	50                   	push   eax
  101b2a:	6a 0e                	push   0xe
  101b2c:	6a 00                	push   0x0
  101b2e:	e8 27 eb ff ff       	call   10065a <printk_color>
  101b33:	83 c4 10             	add    esp,0x10
  101b36:	e8 5a fb ff ff       	call   101695 <pmm_alloc_page>
  101b3b:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  101b3e:	ff 75 f4             	push   DWORD PTR [ebp-0xc]
  101b41:	8d 83 fe f2 ff ff    	lea    eax,[ebx-0xd02]
  101b47:	50                   	push   eax
  101b48:	6a 0e                	push   0xe
  101b4a:	6a 00                	push   0x0
  101b4c:	e8 09 eb ff ff       	call   10065a <printk_color>
  101b51:	83 c4 10             	add    esp,0x10
  101b54:	e8 3c fb ff ff       	call   101695 <pmm_alloc_page>
  101b59:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  101b5c:	ff 75 f4             	push   DWORD PTR [ebp-0xc]
  101b5f:	8d 83 fe f2 ff ff    	lea    eax,[ebx-0xd02]
  101b65:	50                   	push   eax
  101b66:	6a 0e                	push   0xe
  101b68:	6a 00                	push   0x0
  101b6a:	e8 eb ea ff ff       	call   10065a <printk_color>
  101b6f:	83 c4 10             	add    esp,0x10
  101b72:	b8 00 00 00 00       	mov    eax,0x0
  101b77:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101b7a:	c9                   	leave  
  101b7b:	c3                   	ret    

00101b7c <timer_callback>:
  101b7c:	f3 0f 1e fb          	endbr32 
  101b80:	55                   	push   ebp
  101b81:	89 e5                	mov    ebp,esp
  101b83:	53                   	push   ebx
  101b84:	83 ec 04             	sub    esp,0x4
  101b87:	e8 74 14 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101b8c:	05 74 24 00 00       	add    eax,0x2474
  101b91:	8b 90 48 88 08 00    	mov    edx,DWORD PTR [eax+0x88848]
  101b97:	8d 4a 01             	lea    ecx,[edx+0x1]
  101b9a:	89 88 48 88 08 00    	mov    DWORD PTR [eax+0x88848],ecx
  101ba0:	52                   	push   edx
  101ba1:	8d 90 1b f3 ff ff    	lea    edx,[eax-0xce5]
  101ba7:	52                   	push   edx
  101ba8:	6a 04                	push   0x4
  101baa:	6a 00                	push   0x0
  101bac:	89 c3                	mov    ebx,eax
  101bae:	e8 a7 ea ff ff       	call   10065a <printk_color>
  101bb3:	83 c4 10             	add    esp,0x10
  101bb6:	90                   	nop
  101bb7:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101bba:	c9                   	leave  
  101bbb:	c3                   	ret    

00101bbc <init_timer>:
  101bbc:	f3 0f 1e fb          	endbr32 
  101bc0:	55                   	push   ebp
  101bc1:	89 e5                	mov    ebp,esp
  101bc3:	53                   	push   ebx
  101bc4:	83 ec 14             	sub    esp,0x14
  101bc7:	e8 38 14 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  101bcc:	81 c3 34 24 00 00    	add    ebx,0x2434
  101bd2:	83 ec 08             	sub    esp,0x8
  101bd5:	8d 83 7c db ff ff    	lea    eax,[ebx-0x2484]
  101bdb:	50                   	push   eax
  101bdc:	6a 20                	push   0x20
  101bde:	e8 7d f8 ff ff       	call   101460 <register_interrupt_handler>
  101be3:	83 c4 10             	add    esp,0x10
  101be6:	b8 dc 34 12 00       	mov    eax,0x1234dc
  101beb:	ba 00 00 00 00       	mov    edx,0x0
  101bf0:	f7 75 08             	div    DWORD PTR [ebp+0x8]
  101bf3:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  101bf6:	83 ec 08             	sub    esp,0x8
  101bf9:	6a 36                	push   0x36
  101bfb:	6a 43                	push   0x43
  101bfd:	e8 78 fd ff ff       	call   10197a <outb>
  101c02:	83 c4 10             	add    esp,0x10
  101c05:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101c08:	88 45 f3             	mov    BYTE PTR [ebp-0xd],al
  101c0b:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  101c0e:	c1 e8 08             	shr    eax,0x8
  101c11:	88 45 f2             	mov    BYTE PTR [ebp-0xe],al
  101c14:	0f b6 45 f3          	movzx  eax,BYTE PTR [ebp-0xd]
  101c18:	83 ec 08             	sub    esp,0x8
  101c1b:	50                   	push   eax
  101c1c:	6a 40                	push   0x40
  101c1e:	e8 57 fd ff ff       	call   10197a <outb>
  101c23:	83 c4 10             	add    esp,0x10
  101c26:	0f b6 45 f2          	movzx  eax,BYTE PTR [ebp-0xe]
  101c2a:	83 ec 08             	sub    esp,0x8
  101c2d:	50                   	push   eax
  101c2e:	6a 40                	push   0x40
  101c30:	e8 45 fd ff ff       	call   10197a <outb>
  101c35:	83 c4 10             	add    esp,0x10
  101c38:	90                   	nop
  101c39:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101c3c:	c9                   	leave  
  101c3d:	c3                   	ret    

00101c3e <move_cursor>:
  101c3e:	f3 0f 1e fb          	endbr32 
  101c42:	55                   	push   ebp
  101c43:	89 e5                	mov    ebp,esp
  101c45:	53                   	push   ebx
  101c46:	83 ec 14             	sub    esp,0x14
  101c49:	e8 b6 13 00 00       	call   103004 <__x86.get_pc_thunk.bx>
  101c4e:	81 c3 b2 23 00 00    	add    ebx,0x23b2
  101c54:	0f b6 83 4d 88 08 00 	movzx  eax,BYTE PTR [ebx+0x8884d]
  101c5b:	0f b6 d0             	movzx  edx,al
  101c5e:	89 d0                	mov    eax,edx
  101c60:	c1 e0 02             	shl    eax,0x2
  101c63:	01 d0                	add    eax,edx
  101c65:	c1 e0 04             	shl    eax,0x4
  101c68:	89 c2                	mov    edx,eax
  101c6a:	0f b6 83 4c 88 08 00 	movzx  eax,BYTE PTR [ebx+0x8884c]
  101c71:	0f b6 c0             	movzx  eax,al
  101c74:	01 d0                	add    eax,edx
  101c76:	66 89 45 f6          	mov    WORD PTR [ebp-0xa],ax
  101c7a:	83 ec 08             	sub    esp,0x8
  101c7d:	6a 0e                	push   0xe
  101c7f:	68 d4 03 00 00       	push   0x3d4
  101c84:	e8 f1 fc ff ff       	call   10197a <outb>
  101c89:	83 c4 10             	add    esp,0x10
  101c8c:	0f b7 45 f6          	movzx  eax,WORD PTR [ebp-0xa]
  101c90:	66 c1 e8 08          	shr    ax,0x8
  101c94:	0f b6 c0             	movzx  eax,al
  101c97:	83 ec 08             	sub    esp,0x8
  101c9a:	50                   	push   eax
  101c9b:	68 d5 03 00 00       	push   0x3d5
  101ca0:	e8 d5 fc ff ff       	call   10197a <outb>
  101ca5:	83 c4 10             	add    esp,0x10
  101ca8:	83 ec 08             	sub    esp,0x8
  101cab:	6a 0f                	push   0xf
  101cad:	68 d4 03 00 00       	push   0x3d4
  101cb2:	e8 c3 fc ff ff       	call   10197a <outb>
  101cb7:	83 c4 10             	add    esp,0x10
  101cba:	0f b7 45 f6          	movzx  eax,WORD PTR [ebp-0xa]
  101cbe:	0f b6 c0             	movzx  eax,al
  101cc1:	83 ec 08             	sub    esp,0x8
  101cc4:	50                   	push   eax
  101cc5:	68 d5 03 00 00       	push   0x3d5
  101cca:	e8 ab fc ff ff       	call   10197a <outb>
  101ccf:	83 c4 10             	add    esp,0x10
  101cd2:	90                   	nop
  101cd3:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  101cd6:	c9                   	leave  
  101cd7:	c3                   	ret    

00101cd8 <console_clear>:
  101cd8:	f3 0f 1e fb          	endbr32 
  101cdc:	55                   	push   ebp
  101cdd:	89 e5                	mov    ebp,esp
  101cdf:	83 ec 18             	sub    esp,0x18
  101ce2:	e8 19 13 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101ce7:	05 19 23 00 00       	add    eax,0x2319
  101cec:	c6 45 f3 0f          	mov    BYTE PTR [ebp-0xd],0xf
  101cf0:	0f b6 55 f3          	movzx  edx,BYTE PTR [ebp-0xd]
  101cf4:	c1 e2 08             	shl    edx,0x8
  101cf7:	83 ca 20             	or     edx,0x20
  101cfa:	66 89 55 f0          	mov    WORD PTR [ebp-0x10],dx
  101cfe:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  101d05:	eb 18                	jmp    101d1f <console_clear+0x47>
  101d07:	8b 90 08 f0 ff ff    	mov    edx,DWORD PTR [eax-0xff8]
  101d0d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  101d10:	01 c9                	add    ecx,ecx
  101d12:	01 d1                	add    ecx,edx
  101d14:	0f b7 55 f0          	movzx  edx,WORD PTR [ebp-0x10]
  101d18:	66 89 11             	mov    WORD PTR [ecx],dx
  101d1b:	83 45 f4 01          	add    DWORD PTR [ebp-0xc],0x1
  101d1f:	81 7d f4 cf 07 00 00 	cmp    DWORD PTR [ebp-0xc],0x7cf
  101d26:	7e df                	jle    101d07 <console_clear+0x2f>
  101d28:	c6 80 4c 88 08 00 00 	mov    BYTE PTR [eax+0x8884c],0x0
  101d2f:	c6 80 4d 88 08 00 00 	mov    BYTE PTR [eax+0x8884d],0x0
  101d36:	e8 03 ff ff ff       	call   101c3e <move_cursor>
  101d3b:	90                   	nop
  101d3c:	c9                   	leave  
  101d3d:	c3                   	ret    

00101d3e <scroll>:
  101d3e:	f3 0f 1e fb          	endbr32 
  101d42:	55                   	push   ebp
  101d43:	89 e5                	mov    ebp,esp
  101d45:	53                   	push   ebx
  101d46:	83 ec 10             	sub    esp,0x10
  101d49:	e8 b2 12 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101d4e:	05 b2 22 00 00       	add    eax,0x22b2
  101d53:	c6 45 f7 0f          	mov    BYTE PTR [ebp-0x9],0xf
  101d57:	0f b6 55 f7          	movzx  edx,BYTE PTR [ebp-0x9]
  101d5b:	c1 e2 08             	shl    edx,0x8
  101d5e:	83 ca 20             	or     edx,0x20
  101d61:	66 89 55 f4          	mov    WORD PTR [ebp-0xc],dx
  101d65:	0f b6 90 4d 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884d]
  101d6c:	80 fa 18             	cmp    dl,0x18
  101d6f:	76 6a                	jbe    101ddb <scroll+0x9d>
  101d71:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [ebp-0x8],0x0
  101d78:	eb 27                	jmp    101da1 <scroll+0x63>
  101d7a:	8b 90 08 f0 ff ff    	mov    edx,DWORD PTR [eax-0xff8]
  101d80:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  101d83:	83 c1 50             	add    ecx,0x50
  101d86:	01 c9                	add    ecx,ecx
  101d88:	01 ca                	add    edx,ecx
  101d8a:	8b 88 08 f0 ff ff    	mov    ecx,DWORD PTR [eax-0xff8]
  101d90:	8b 5d f8             	mov    ebx,DWORD PTR [ebp-0x8]
  101d93:	01 db                	add    ebx,ebx
  101d95:	01 d9                	add    ecx,ebx
  101d97:	0f b7 12             	movzx  edx,WORD PTR [edx]
  101d9a:	66 89 11             	mov    WORD PTR [ecx],dx
  101d9d:	83 45 f8 01          	add    DWORD PTR [ebp-0x8],0x1
  101da1:	81 7d f8 7f 07 00 00 	cmp    DWORD PTR [ebp-0x8],0x77f
  101da8:	7e d0                	jle    101d7a <scroll+0x3c>
  101daa:	c7 45 f8 80 07 00 00 	mov    DWORD PTR [ebp-0x8],0x780
  101db1:	eb 18                	jmp    101dcb <scroll+0x8d>
  101db3:	8b 90 08 f0 ff ff    	mov    edx,DWORD PTR [eax-0xff8]
  101db9:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  101dbc:	01 c9                	add    ecx,ecx
  101dbe:	01 d1                	add    ecx,edx
  101dc0:	0f b7 55 f4          	movzx  edx,WORD PTR [ebp-0xc]
  101dc4:	66 89 11             	mov    WORD PTR [ecx],dx
  101dc7:	83 45 f8 01          	add    DWORD PTR [ebp-0x8],0x1
  101dcb:	81 7d f8 cf 07 00 00 	cmp    DWORD PTR [ebp-0x8],0x7cf
  101dd2:	7e df                	jle    101db3 <scroll+0x75>
  101dd4:	c6 80 4d 88 08 00 18 	mov    BYTE PTR [eax+0x8884d],0x18
  101ddb:	90                   	nop
  101ddc:	83 c4 10             	add    esp,0x10
  101ddf:	5b                   	pop    ebx
  101de0:	5d                   	pop    ebp
  101de1:	c3                   	ret    

00101de2 <console_putc_color>:
  101de2:	f3 0f 1e fb          	endbr32 
  101de6:	55                   	push   ebp
  101de7:	89 e5                	mov    ebp,esp
  101de9:	56                   	push   esi
  101dea:	53                   	push   ebx
  101deb:	83 ec 20             	sub    esp,0x20
  101dee:	e8 0d 12 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101df3:	05 0d 22 00 00       	add    eax,0x220d
  101df8:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101dfb:	88 55 e4             	mov    BYTE PTR [ebp-0x1c],dl
  101dfe:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  101e01:	88 55 f7             	mov    BYTE PTR [ebp-0x9],dl
  101e04:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  101e07:	88 55 f6             	mov    BYTE PTR [ebp-0xa],dl
  101e0a:	0f b6 55 f7          	movzx  edx,BYTE PTR [ebp-0x9]
  101e0e:	c1 e2 04             	shl    edx,0x4
  101e11:	89 d1                	mov    ecx,edx
  101e13:	0f b6 55 f6          	movzx  edx,BYTE PTR [ebp-0xa]
  101e17:	83 e2 0f             	and    edx,0xf
  101e1a:	09 ca                	or     edx,ecx
  101e1c:	88 55 f5             	mov    BYTE PTR [ebp-0xb],dl
  101e1f:	0f b6 55 f5          	movzx  edx,BYTE PTR [ebp-0xb]
  101e23:	c1 e2 08             	shl    edx,0x8
  101e26:	66 89 55 f2          	mov    WORD PTR [ebp-0xe],dx
  101e2a:	80 7d e4 08          	cmp    BYTE PTR [ebp-0x1c],0x8
  101e2e:	75 20                	jne    101e50 <console_putc_color+0x6e>
  101e30:	0f b6 90 4c 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884c]
  101e37:	84 d2                	test   dl,dl
  101e39:	74 15                	je     101e50 <console_putc_color+0x6e>
  101e3b:	0f b6 90 4c 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884c]
  101e42:	83 ea 01             	sub    edx,0x1
  101e45:	88 90 4c 88 08 00    	mov    BYTE PTR [eax+0x8884c],dl
  101e4b:	e9 a0 00 00 00       	jmp    101ef0 <console_putc_color+0x10e>
  101e50:	80 7d e4 09          	cmp    BYTE PTR [ebp-0x1c],0x9
  101e54:	75 18                	jne    101e6e <console_putc_color+0x8c>
  101e56:	0f b6 90 4c 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884c]
  101e5d:	83 c2 08             	add    edx,0x8
  101e60:	83 e2 f8             	and    edx,0xfffffff8
  101e63:	88 90 4c 88 08 00    	mov    BYTE PTR [eax+0x8884c],dl
  101e69:	e9 82 00 00 00       	jmp    101ef0 <console_putc_color+0x10e>
  101e6e:	80 7d e4 0d          	cmp    BYTE PTR [ebp-0x1c],0xd
  101e72:	75 09                	jne    101e7d <console_putc_color+0x9b>
  101e74:	c6 80 4c 88 08 00 00 	mov    BYTE PTR [eax+0x8884c],0x0
  101e7b:	eb 73                	jmp    101ef0 <console_putc_color+0x10e>
  101e7d:	80 7d e4 0a          	cmp    BYTE PTR [ebp-0x1c],0xa
  101e81:	75 19                	jne    101e9c <console_putc_color+0xba>
  101e83:	c6 80 4c 88 08 00 00 	mov    BYTE PTR [eax+0x8884c],0x0
  101e8a:	0f b6 90 4d 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884d]
  101e91:	83 c2 01             	add    edx,0x1
  101e94:	88 90 4d 88 08 00    	mov    BYTE PTR [eax+0x8884d],dl
  101e9a:	eb 54                	jmp    101ef0 <console_putc_color+0x10e>
  101e9c:	80 7d e4 1f          	cmp    BYTE PTR [ebp-0x1c],0x1f
  101ea0:	7e 4e                	jle    101ef0 <console_putc_color+0x10e>
  101ea2:	66 0f be 4d e4       	movsx  cx,BYTE PTR [ebp-0x1c]
  101ea7:	0f b7 55 f2          	movzx  edx,WORD PTR [ebp-0xe]
  101eab:	89 ce                	mov    esi,ecx
  101ead:	09 d6                	or     esi,edx
  101eaf:	8b 98 08 f0 ff ff    	mov    ebx,DWORD PTR [eax-0xff8]
  101eb5:	0f b6 90 4d 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884d]
  101ebc:	0f b6 ca             	movzx  ecx,dl
  101ebf:	89 ca                	mov    edx,ecx
  101ec1:	c1 e2 02             	shl    edx,0x2
  101ec4:	01 ca                	add    edx,ecx
  101ec6:	c1 e2 04             	shl    edx,0x4
  101ec9:	89 d1                	mov    ecx,edx
  101ecb:	0f b6 90 4c 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884c]
  101ed2:	0f b6 d2             	movzx  edx,dl
  101ed5:	01 ca                	add    edx,ecx
  101ed7:	01 d2                	add    edx,edx
  101ed9:	01 da                	add    edx,ebx
  101edb:	89 f1                	mov    ecx,esi
  101edd:	66 89 0a             	mov    WORD PTR [edx],cx
  101ee0:	0f b6 90 4c 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884c]
  101ee7:	83 c2 01             	add    edx,0x1
  101eea:	88 90 4c 88 08 00    	mov    BYTE PTR [eax+0x8884c],dl
  101ef0:	0f b6 90 4c 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884c]
  101ef7:	80 fa 4f             	cmp    dl,0x4f
  101efa:	76 17                	jbe    101f13 <console_putc_color+0x131>
  101efc:	c6 80 4c 88 08 00 00 	mov    BYTE PTR [eax+0x8884c],0x0
  101f03:	0f b6 90 4d 88 08 00 	movzx  edx,BYTE PTR [eax+0x8884d]
  101f0a:	83 c2 01             	add    edx,0x1
  101f0d:	88 90 4d 88 08 00    	mov    BYTE PTR [eax+0x8884d],dl
  101f13:	e8 26 fe ff ff       	call   101d3e <scroll>
  101f18:	e8 21 fd ff ff       	call   101c3e <move_cursor>
  101f1d:	90                   	nop
  101f1e:	83 c4 20             	add    esp,0x20
  101f21:	5b                   	pop    ebx
  101f22:	5e                   	pop    esi
  101f23:	5d                   	pop    ebp
  101f24:	c3                   	ret    

00101f25 <console_write>:
  101f25:	f3 0f 1e fb          	endbr32 
  101f29:	55                   	push   ebp
  101f2a:	89 e5                	mov    ebp,esp
  101f2c:	83 ec 08             	sub    esp,0x8
  101f2f:	e8 cc 10 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101f34:	05 cc 20 00 00       	add    eax,0x20cc
  101f39:	eb 1f                	jmp    101f5a <console_write+0x35>
  101f3b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101f3e:	8d 50 01             	lea    edx,[eax+0x1]
  101f41:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  101f44:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101f47:	0f be c0             	movsx  eax,al
  101f4a:	83 ec 04             	sub    esp,0x4
  101f4d:	6a 0f                	push   0xf
  101f4f:	6a 00                	push   0x0
  101f51:	50                   	push   eax
  101f52:	e8 8b fe ff ff       	call   101de2 <console_putc_color>
  101f57:	83 c4 10             	add    esp,0x10
  101f5a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101f5d:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101f60:	84 c0                	test   al,al
  101f62:	75 d7                	jne    101f3b <console_write+0x16>
  101f64:	90                   	nop
  101f65:	90                   	nop
  101f66:	c9                   	leave  
  101f67:	c3                   	ret    

00101f68 <console_write_color>:
  101f68:	f3 0f 1e fb          	endbr32 
  101f6c:	55                   	push   ebp
  101f6d:	89 e5                	mov    ebp,esp
  101f6f:	83 ec 08             	sub    esp,0x8
  101f72:	e8 89 10 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101f77:	05 89 20 00 00       	add    eax,0x2089
  101f7c:	eb 21                	jmp    101f9f <console_write_color+0x37>
  101f7e:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101f81:	8d 50 01             	lea    edx,[eax+0x1]
  101f84:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  101f87:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101f8a:	0f be c0             	movsx  eax,al
  101f8d:	83 ec 04             	sub    esp,0x4
  101f90:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  101f93:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  101f96:	50                   	push   eax
  101f97:	e8 46 fe ff ff       	call   101de2 <console_putc_color>
  101f9c:	83 c4 10             	add    esp,0x10
  101f9f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  101fa2:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  101fa5:	84 c0                	test   al,al
  101fa7:	75 d5                	jne    101f7e <console_write_color+0x16>
  101fa9:	90                   	nop
  101faa:	90                   	nop
  101fab:	c9                   	leave  
  101fac:	c3                   	ret    

00101fad <console_write_hex>:
  101fad:	f3 0f 1e fb          	endbr32 
  101fb1:	55                   	push   ebp
  101fb2:	89 e5                	mov    ebp,esp
  101fb4:	83 ec 18             	sub    esp,0x18
  101fb7:	e8 44 10 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  101fbc:	05 44 20 00 00       	add    eax,0x2044
  101fc1:	c6 45 f7 01          	mov    BYTE PTR [ebp-0x9],0x1
  101fc5:	83 ec 04             	sub    esp,0x4
  101fc8:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  101fcb:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  101fce:	8d 80 25 f3 ff ff    	lea    eax,[eax-0xcdb]
  101fd4:	50                   	push   eax
  101fd5:	e8 8e ff ff ff       	call   101f68 <console_write_color>
  101fda:	83 c4 10             	add    esp,0x10
  101fdd:	c7 45 f0 1c 00 00 00 	mov    DWORD PTR [ebp-0x10],0x1c
  101fe4:	eb 67                	jmp    10204d <console_write_hex+0xa0>
  101fe6:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  101fe9:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  101fec:	89 c1                	mov    ecx,eax
  101fee:	d3 ea                	shr    edx,cl
  101ff0:	89 d0                	mov    eax,edx
  101ff2:	83 e0 0f             	and    eax,0xf
  101ff5:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  101ff8:	83 7d ec 00          	cmp    DWORD PTR [ebp-0x14],0x0
  101ffc:	75 06                	jne    102004 <console_write_hex+0x57>
  101ffe:	80 7d f7 00          	cmp    BYTE PTR [ebp-0x9],0x0
  102002:	75 44                	jne    102048 <console_write_hex+0x9b>
  102004:	c6 45 f7 00          	mov    BYTE PTR [ebp-0x9],0x0
  102008:	83 7d ec 09          	cmp    DWORD PTR [ebp-0x14],0x9
  10200c:	7e 1d                	jle    10202b <console_write_hex+0x7e>
  10200e:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  102011:	83 c0 57             	add    eax,0x57
  102014:	0f be c0             	movsx  eax,al
  102017:	83 ec 04             	sub    esp,0x4
  10201a:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  10201d:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  102020:	50                   	push   eax
  102021:	e8 bc fd ff ff       	call   101de2 <console_putc_color>
  102026:	83 c4 10             	add    esp,0x10
  102029:	eb 1e                	jmp    102049 <console_write_hex+0x9c>
  10202b:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  10202e:	83 c0 30             	add    eax,0x30
  102031:	0f be c0             	movsx  eax,al
  102034:	83 ec 04             	sub    esp,0x4
  102037:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  10203a:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  10203d:	50                   	push   eax
  10203e:	e8 9f fd ff ff       	call   101de2 <console_putc_color>
  102043:	83 c4 10             	add    esp,0x10
  102046:	eb 01                	jmp    102049 <console_write_hex+0x9c>
  102048:	90                   	nop
  102049:	83 6d f0 04          	sub    DWORD PTR [ebp-0x10],0x4
  10204d:	83 7d f0 00          	cmp    DWORD PTR [ebp-0x10],0x0
  102051:	79 93                	jns    101fe6 <console_write_hex+0x39>
  102053:	90                   	nop
  102054:	90                   	nop
  102055:	c9                   	leave  
  102056:	c3                   	ret    

00102057 <console_write_dec>:
  102057:	f3 0f 1e fb          	endbr32 
  10205b:	55                   	push   ebp
  10205c:	89 e5                	mov    ebp,esp
  10205e:	83 ec 58             	sub    esp,0x58
  102061:	e8 9a 0f 00 00       	call   103000 <__x86.get_pc_thunk.ax>
  102066:	05 9a 1f 00 00       	add    eax,0x1f9a
  10206b:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  10206f:	75 18                	jne    102089 <console_write_dec+0x32>
  102071:	83 ec 04             	sub    esp,0x4
  102074:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  102077:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  10207a:	6a 30                	push   0x30
  10207c:	e8 61 fd ff ff       	call   101de2 <console_putc_color>
  102081:	83 c4 10             	add    esp,0x10
  102084:	e9 b0 00 00 00       	jmp    102139 <console_write_dec+0xe2>
  102089:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  10208c:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  10208f:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  102096:	eb 43                	jmp    1020db <console_write_dec+0x84>
  102098:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  10209b:	ba cd cc cc cc       	mov    edx,0xcccccccd
  1020a0:	89 c8                	mov    eax,ecx
  1020a2:	f7 e2                	mul    edx
  1020a4:	c1 ea 03             	shr    edx,0x3
  1020a7:	89 d0                	mov    eax,edx
  1020a9:	c1 e0 02             	shl    eax,0x2
  1020ac:	01 d0                	add    eax,edx
  1020ae:	01 c0                	add    eax,eax
  1020b0:	29 c1                	sub    ecx,eax
  1020b2:	89 ca                	mov    edx,ecx
  1020b4:	89 d0                	mov    eax,edx
  1020b6:	83 c0 30             	add    eax,0x30
  1020b9:	89 c1                	mov    ecx,eax
  1020bb:	8d 55 cc             	lea    edx,[ebp-0x34]
  1020be:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  1020c1:	01 d0                	add    eax,edx
  1020c3:	88 08                	mov    BYTE PTR [eax],cl
  1020c5:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  1020c8:	ba cd cc cc cc       	mov    edx,0xcccccccd
  1020cd:	f7 e2                	mul    edx
  1020cf:	89 d0                	mov    eax,edx
  1020d1:	c1 e8 03             	shr    eax,0x3
  1020d4:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  1020d7:	83 45 f0 01          	add    DWORD PTR [ebp-0x10],0x1
  1020db:	83 7d f4 00          	cmp    DWORD PTR [ebp-0xc],0x0
  1020df:	75 b7                	jne    102098 <console_write_dec+0x41>
  1020e1:	8d 55 cc             	lea    edx,[ebp-0x34]
  1020e4:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  1020e7:	01 d0                	add    eax,edx
  1020e9:	c6 00 00             	mov    BYTE PTR [eax],0x0
  1020ec:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  1020ef:	8d 50 ff             	lea    edx,[eax-0x1]
  1020f2:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  1020f5:	c6 44 05 ac 00       	mov    BYTE PTR [ebp+eax*1-0x54],0x0
  1020fa:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  102101:	eb 1b                	jmp    10211e <console_write_dec+0xc7>
  102103:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  102106:	8d 42 01             	lea    eax,[edx+0x1]
  102109:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  10210c:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  10210f:	8d 48 ff             	lea    ecx,[eax-0x1]
  102112:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  102115:	0f b6 54 15 cc       	movzx  edx,BYTE PTR [ebp+edx*1-0x34]
  10211a:	88 54 05 ac          	mov    BYTE PTR [ebp+eax*1-0x54],dl
  10211e:	83 7d f0 00          	cmp    DWORD PTR [ebp-0x10],0x0
  102122:	79 df                	jns    102103 <console_write_dec+0xac>
  102124:	83 ec 04             	sub    esp,0x4
  102127:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  10212a:	ff 75 0c             	push   DWORD PTR [ebp+0xc]
  10212d:	8d 45 ac             	lea    eax,[ebp-0x54]
  102130:	50                   	push   eax
  102131:	e8 32 fe ff ff       	call   101f68 <console_write_color>
  102136:	83 c4 10             	add    esp,0x10
  102139:	c9                   	leave  
  10213a:	c3                   	ret    
  10213b:	66 90                	xchg   ax,ax
  10213d:	66 90                	xchg   ax,ax
  10213f:	66 90                	xchg   ax,ax
  102141:	66 90                	xchg   ax,ax
  102143:	66 90                	xchg   ax,ax
  102145:	66 90                	xchg   ax,ax
  102147:	66 90                	xchg   ax,ax
  102149:	66 90                	xchg   ax,ax
  10214b:	66 90                	xchg   ax,ax
  10214d:	66 90                	xchg   ax,ax
  10214f:	66 90                	xchg   ax,ax
  102151:	66 90                	xchg   ax,ax
  102153:	66 90                	xchg   ax,ax
  102155:	66 90                	xchg   ax,ax
  102157:	66 90                	xchg   ax,ax
  102159:	66 90                	xchg   ax,ax
  10215b:	66 90                	xchg   ax,ax
  10215d:	66 90                	xchg   ax,ax
  10215f:	66 90                	xchg   ax,ax
  102161:	66 90                	xchg   ax,ax
  102163:	66 90                	xchg   ax,ax
  102165:	66 90                	xchg   ax,ax
  102167:	66 90                	xchg   ax,ax
  102169:	66 90                	xchg   ax,ax
  10216b:	66 90                	xchg   ax,ax
  10216d:	66 90                	xchg   ax,ax
  10216f:	66 90                	xchg   ax,ax
  102171:	66 90                	xchg   ax,ax
  102173:	66 90                	xchg   ax,ax
  102175:	66 90                	xchg   ax,ax
  102177:	66 90                	xchg   ax,ax
  102179:	66 90                	xchg   ax,ax
  10217b:	66 90                	xchg   ax,ax
  10217d:	66 90                	xchg   ax,ax
  10217f:	66 90                	xchg   ax,ax
  102181:	66 90                	xchg   ax,ax
  102183:	66 90                	xchg   ax,ax
  102185:	66 90                	xchg   ax,ax
  102187:	66 90                	xchg   ax,ax
  102189:	66 90                	xchg   ax,ax
  10218b:	66 90                	xchg   ax,ax
  10218d:	66 90                	xchg   ax,ax
  10218f:	66 90                	xchg   ax,ax
  102191:	66 90                	xchg   ax,ax
  102193:	66 90                	xchg   ax,ax
  102195:	66 90                	xchg   ax,ax
  102197:	66 90                	xchg   ax,ax
  102199:	66 90                	xchg   ax,ax
  10219b:	66 90                	xchg   ax,ax
  10219d:	66 90                	xchg   ax,ax
  10219f:	66 90                	xchg   ax,ax
  1021a1:	66 90                	xchg   ax,ax
  1021a3:	66 90                	xchg   ax,ax
  1021a5:	66 90                	xchg   ax,ax
  1021a7:	66 90                	xchg   ax,ax
  1021a9:	66 90                	xchg   ax,ax
  1021ab:	66 90                	xchg   ax,ax
  1021ad:	66 90                	xchg   ax,ax
  1021af:	66 90                	xchg   ax,ax
  1021b1:	66 90                	xchg   ax,ax
  1021b3:	66 90                	xchg   ax,ax
  1021b5:	66 90                	xchg   ax,ax
  1021b7:	66 90                	xchg   ax,ax
  1021b9:	66 90                	xchg   ax,ax
  1021bb:	66 90                	xchg   ax,ax
  1021bd:	66 90                	xchg   ax,ax
  1021bf:	66 90                	xchg   ax,ax
  1021c1:	66 90                	xchg   ax,ax
  1021c3:	66 90                	xchg   ax,ax
  1021c5:	66 90                	xchg   ax,ax
  1021c7:	66 90                	xchg   ax,ax
  1021c9:	66 90                	xchg   ax,ax
  1021cb:	66 90                	xchg   ax,ax
  1021cd:	66 90                	xchg   ax,ax
  1021cf:	66 90                	xchg   ax,ax
  1021d1:	66 90                	xchg   ax,ax
  1021d3:	66 90                	xchg   ax,ax
  1021d5:	66 90                	xchg   ax,ax
  1021d7:	66 90                	xchg   ax,ax
  1021d9:	66 90                	xchg   ax,ax
  1021db:	66 90                	xchg   ax,ax
  1021dd:	66 90                	xchg   ax,ax
  1021df:	66 90                	xchg   ax,ax
  1021e1:	66 90                	xchg   ax,ax
  1021e3:	66 90                	xchg   ax,ax
  1021e5:	66 90                	xchg   ax,ax
  1021e7:	66 90                	xchg   ax,ax
  1021e9:	66 90                	xchg   ax,ax
  1021eb:	66 90                	xchg   ax,ax
  1021ed:	66 90                	xchg   ax,ax
  1021ef:	66 90                	xchg   ax,ax
  1021f1:	66 90                	xchg   ax,ax
  1021f3:	66 90                	xchg   ax,ax
  1021f5:	66 90                	xchg   ax,ax
  1021f7:	66 90                	xchg   ax,ax
  1021f9:	66 90                	xchg   ax,ax
  1021fb:	66 90                	xchg   ax,ax
  1021fd:	66 90                	xchg   ax,ax
  1021ff:	66 90                	xchg   ax,ax
  102201:	66 90                	xchg   ax,ax
  102203:	66 90                	xchg   ax,ax
  102205:	66 90                	xchg   ax,ax
  102207:	66 90                	xchg   ax,ax
  102209:	66 90                	xchg   ax,ax
  10220b:	66 90                	xchg   ax,ax
  10220d:	66 90                	xchg   ax,ax
  10220f:	66 90                	xchg   ax,ax
  102211:	66 90                	xchg   ax,ax
  102213:	66 90                	xchg   ax,ax
  102215:	66 90                	xchg   ax,ax
  102217:	66 90                	xchg   ax,ax
  102219:	66 90                	xchg   ax,ax
  10221b:	66 90                	xchg   ax,ax
  10221d:	66 90                	xchg   ax,ax
  10221f:	66 90                	xchg   ax,ax
  102221:	66 90                	xchg   ax,ax
  102223:	66 90                	xchg   ax,ax
  102225:	66 90                	xchg   ax,ax
  102227:	66 90                	xchg   ax,ax
  102229:	66 90                	xchg   ax,ax
  10222b:	66 90                	xchg   ax,ax
  10222d:	66 90                	xchg   ax,ax
  10222f:	66 90                	xchg   ax,ax
  102231:	66 90                	xchg   ax,ax
  102233:	66 90                	xchg   ax,ax
  102235:	66 90                	xchg   ax,ax
  102237:	66 90                	xchg   ax,ax
  102239:	66 90                	xchg   ax,ax
  10223b:	66 90                	xchg   ax,ax
  10223d:	66 90                	xchg   ax,ax
  10223f:	66 90                	xchg   ax,ax
  102241:	66 90                	xchg   ax,ax
  102243:	66 90                	xchg   ax,ax
  102245:	66 90                	xchg   ax,ax
  102247:	66 90                	xchg   ax,ax
  102249:	66 90                	xchg   ax,ax
  10224b:	66 90                	xchg   ax,ax
  10224d:	66 90                	xchg   ax,ax
  10224f:	66 90                	xchg   ax,ax
  102251:	66 90                	xchg   ax,ax
  102253:	66 90                	xchg   ax,ax
  102255:	66 90                	xchg   ax,ax
  102257:	66 90                	xchg   ax,ax
  102259:	66 90                	xchg   ax,ax
  10225b:	66 90                	xchg   ax,ax
  10225d:	66 90                	xchg   ax,ax
  10225f:	66 90                	xchg   ax,ax
  102261:	66 90                	xchg   ax,ax
  102263:	66 90                	xchg   ax,ax
  102265:	66 90                	xchg   ax,ax
  102267:	66 90                	xchg   ax,ax
  102269:	66 90                	xchg   ax,ax
  10226b:	66 90                	xchg   ax,ax
  10226d:	66 90                	xchg   ax,ax
  10226f:	66 90                	xchg   ax,ax
  102271:	66 90                	xchg   ax,ax
  102273:	66 90                	xchg   ax,ax
  102275:	66 90                	xchg   ax,ax
  102277:	66 90                	xchg   ax,ax
  102279:	66 90                	xchg   ax,ax
  10227b:	66 90                	xchg   ax,ax
  10227d:	66 90                	xchg   ax,ax
  10227f:	66 90                	xchg   ax,ax
  102281:	66 90                	xchg   ax,ax
  102283:	66 90                	xchg   ax,ax
  102285:	66 90                	xchg   ax,ax
  102287:	66 90                	xchg   ax,ax
  102289:	66 90                	xchg   ax,ax
  10228b:	66 90                	xchg   ax,ax
  10228d:	66 90                	xchg   ax,ax
  10228f:	66 90                	xchg   ax,ax
  102291:	66 90                	xchg   ax,ax
  102293:	66 90                	xchg   ax,ax
  102295:	66 90                	xchg   ax,ax
  102297:	66 90                	xchg   ax,ax
  102299:	66 90                	xchg   ax,ax
  10229b:	66 90                	xchg   ax,ax
  10229d:	66 90                	xchg   ax,ax
  10229f:	66 90                	xchg   ax,ax
  1022a1:	66 90                	xchg   ax,ax
  1022a3:	66 90                	xchg   ax,ax
  1022a5:	66 90                	xchg   ax,ax
  1022a7:	66 90                	xchg   ax,ax
  1022a9:	66 90                	xchg   ax,ax
  1022ab:	66 90                	xchg   ax,ax
  1022ad:	66 90                	xchg   ax,ax
  1022af:	66 90                	xchg   ax,ax
  1022b1:	66 90                	xchg   ax,ax
  1022b3:	66 90                	xchg   ax,ax
  1022b5:	66 90                	xchg   ax,ax
  1022b7:	66 90                	xchg   ax,ax
  1022b9:	66 90                	xchg   ax,ax
  1022bb:	66 90                	xchg   ax,ax
  1022bd:	66 90                	xchg   ax,ax
  1022bf:	66 90                	xchg   ax,ax
  1022c1:	66 90                	xchg   ax,ax
  1022c3:	66 90                	xchg   ax,ax
  1022c5:	66 90                	xchg   ax,ax
  1022c7:	66 90                	xchg   ax,ax
  1022c9:	66 90                	xchg   ax,ax
  1022cb:	66 90                	xchg   ax,ax
  1022cd:	66 90                	xchg   ax,ax
  1022cf:	66 90                	xchg   ax,ax
  1022d1:	66 90                	xchg   ax,ax
  1022d3:	66 90                	xchg   ax,ax
  1022d5:	66 90                	xchg   ax,ax
  1022d7:	66 90                	xchg   ax,ax
  1022d9:	66 90                	xchg   ax,ax
  1022db:	66 90                	xchg   ax,ax
  1022dd:	66 90                	xchg   ax,ax
  1022df:	66 90                	xchg   ax,ax
  1022e1:	66 90                	xchg   ax,ax
  1022e3:	66 90                	xchg   ax,ax
  1022e5:	66 90                	xchg   ax,ax
  1022e7:	66 90                	xchg   ax,ax
  1022e9:	66 90                	xchg   ax,ax
  1022eb:	66 90                	xchg   ax,ax
  1022ed:	66 90                	xchg   ax,ax
  1022ef:	66 90                	xchg   ax,ax
  1022f1:	66 90                	xchg   ax,ax
  1022f3:	66 90                	xchg   ax,ax
  1022f5:	66 90                	xchg   ax,ax
  1022f7:	66 90                	xchg   ax,ax
  1022f9:	66 90                	xchg   ax,ax
  1022fb:	66 90                	xchg   ax,ax
  1022fd:	66 90                	xchg   ax,ax
  1022ff:	66 90                	xchg   ax,ax
  102301:	66 90                	xchg   ax,ax
  102303:	66 90                	xchg   ax,ax
  102305:	66 90                	xchg   ax,ax
  102307:	66 90                	xchg   ax,ax
  102309:	66 90                	xchg   ax,ax
  10230b:	66 90                	xchg   ax,ax
  10230d:	66 90                	xchg   ax,ax
  10230f:	66 90                	xchg   ax,ax
  102311:	66 90                	xchg   ax,ax
  102313:	66 90                	xchg   ax,ax
  102315:	66 90                	xchg   ax,ax
  102317:	66 90                	xchg   ax,ax
  102319:	66 90                	xchg   ax,ax
  10231b:	66 90                	xchg   ax,ax
  10231d:	66 90                	xchg   ax,ax
  10231f:	66 90                	xchg   ax,ax
  102321:	66 90                	xchg   ax,ax
  102323:	66 90                	xchg   ax,ax
  102325:	66 90                	xchg   ax,ax
  102327:	66 90                	xchg   ax,ax
  102329:	66 90                	xchg   ax,ax
  10232b:	66 90                	xchg   ax,ax
  10232d:	66 90                	xchg   ax,ax
  10232f:	66 90                	xchg   ax,ax
  102331:	66 90                	xchg   ax,ax
  102333:	66 90                	xchg   ax,ax
  102335:	66 90                	xchg   ax,ax
  102337:	66 90                	xchg   ax,ax
  102339:	66 90                	xchg   ax,ax
  10233b:	66 90                	xchg   ax,ax
  10233d:	66 90                	xchg   ax,ax
  10233f:	66 90                	xchg   ax,ax
  102341:	66 90                	xchg   ax,ax
  102343:	66 90                	xchg   ax,ax
  102345:	66 90                	xchg   ax,ax
  102347:	66 90                	xchg   ax,ax
  102349:	66 90                	xchg   ax,ax
  10234b:	66 90                	xchg   ax,ax
  10234d:	66 90                	xchg   ax,ax
  10234f:	66 90                	xchg   ax,ax
  102351:	66 90                	xchg   ax,ax
  102353:	66 90                	xchg   ax,ax
  102355:	66 90                	xchg   ax,ax
  102357:	66 90                	xchg   ax,ax
  102359:	66 90                	xchg   ax,ax
  10235b:	66 90                	xchg   ax,ax
  10235d:	66 90                	xchg   ax,ax
  10235f:	66 90                	xchg   ax,ax
  102361:	66 90                	xchg   ax,ax
  102363:	66 90                	xchg   ax,ax
  102365:	66 90                	xchg   ax,ax
  102367:	66 90                	xchg   ax,ax
  102369:	66 90                	xchg   ax,ax
  10236b:	66 90                	xchg   ax,ax
  10236d:	66 90                	xchg   ax,ax
  10236f:	66 90                	xchg   ax,ax
  102371:	66 90                	xchg   ax,ax
  102373:	66 90                	xchg   ax,ax
  102375:	66 90                	xchg   ax,ax
  102377:	66 90                	xchg   ax,ax
  102379:	66 90                	xchg   ax,ax
  10237b:	66 90                	xchg   ax,ax
  10237d:	66 90                	xchg   ax,ax
  10237f:	66 90                	xchg   ax,ax
  102381:	66 90                	xchg   ax,ax
  102383:	66 90                	xchg   ax,ax
  102385:	66 90                	xchg   ax,ax
  102387:	66 90                	xchg   ax,ax
  102389:	66 90                	xchg   ax,ax
  10238b:	66 90                	xchg   ax,ax
  10238d:	66 90                	xchg   ax,ax
  10238f:	66 90                	xchg   ax,ax
  102391:	66 90                	xchg   ax,ax
  102393:	66 90                	xchg   ax,ax
  102395:	66 90                	xchg   ax,ax
  102397:	66 90                	xchg   ax,ax
  102399:	66 90                	xchg   ax,ax
  10239b:	66 90                	xchg   ax,ax
  10239d:	66 90                	xchg   ax,ax
  10239f:	66 90                	xchg   ax,ax
  1023a1:	66 90                	xchg   ax,ax
  1023a3:	66 90                	xchg   ax,ax
  1023a5:	66 90                	xchg   ax,ax
  1023a7:	66 90                	xchg   ax,ax
  1023a9:	66 90                	xchg   ax,ax
  1023ab:	66 90                	xchg   ax,ax
  1023ad:	66 90                	xchg   ax,ax
  1023af:	66 90                	xchg   ax,ax
  1023b1:	66 90                	xchg   ax,ax
  1023b3:	66 90                	xchg   ax,ax
  1023b5:	66 90                	xchg   ax,ax
  1023b7:	66 90                	xchg   ax,ax
  1023b9:	66 90                	xchg   ax,ax
  1023bb:	66 90                	xchg   ax,ax
  1023bd:	66 90                	xchg   ax,ax
  1023bf:	66 90                	xchg   ax,ax
  1023c1:	66 90                	xchg   ax,ax
  1023c3:	66 90                	xchg   ax,ax
  1023c5:	66 90                	xchg   ax,ax
  1023c7:	66 90                	xchg   ax,ax
  1023c9:	66 90                	xchg   ax,ax
  1023cb:	66 90                	xchg   ax,ax
  1023cd:	66 90                	xchg   ax,ax
  1023cf:	66 90                	xchg   ax,ax
  1023d1:	66 90                	xchg   ax,ax
  1023d3:	66 90                	xchg   ax,ax
  1023d5:	66 90                	xchg   ax,ax
  1023d7:	66 90                	xchg   ax,ax
  1023d9:	66 90                	xchg   ax,ax
  1023db:	66 90                	xchg   ax,ax
  1023dd:	66 90                	xchg   ax,ax
  1023df:	66 90                	xchg   ax,ax
  1023e1:	66 90                	xchg   ax,ax
  1023e3:	66 90                	xchg   ax,ax
  1023e5:	66 90                	xchg   ax,ax
  1023e7:	66 90                	xchg   ax,ax
  1023e9:	66 90                	xchg   ax,ax
  1023eb:	66 90                	xchg   ax,ax
  1023ed:	66 90                	xchg   ax,ax
  1023ef:	66 90                	xchg   ax,ax
  1023f1:	66 90                	xchg   ax,ax
  1023f3:	66 90                	xchg   ax,ax
  1023f5:	66 90                	xchg   ax,ax
  1023f7:	66 90                	xchg   ax,ax
  1023f9:	66 90                	xchg   ax,ax
  1023fb:	66 90                	xchg   ax,ax
  1023fd:	66 90                	xchg   ax,ax
  1023ff:	66 90                	xchg   ax,ax
  102401:	66 90                	xchg   ax,ax
  102403:	66 90                	xchg   ax,ax
  102405:	66 90                	xchg   ax,ax
  102407:	66 90                	xchg   ax,ax
  102409:	66 90                	xchg   ax,ax
  10240b:	66 90                	xchg   ax,ax
  10240d:	66 90                	xchg   ax,ax
  10240f:	66 90                	xchg   ax,ax
  102411:	66 90                	xchg   ax,ax
  102413:	66 90                	xchg   ax,ax
  102415:	66 90                	xchg   ax,ax
  102417:	66 90                	xchg   ax,ax
  102419:	66 90                	xchg   ax,ax
  10241b:	66 90                	xchg   ax,ax
  10241d:	66 90                	xchg   ax,ax
  10241f:	66 90                	xchg   ax,ax
  102421:	66 90                	xchg   ax,ax
  102423:	66 90                	xchg   ax,ax
  102425:	66 90                	xchg   ax,ax
  102427:	66 90                	xchg   ax,ax
  102429:	66 90                	xchg   ax,ax
  10242b:	66 90                	xchg   ax,ax
  10242d:	66 90                	xchg   ax,ax
  10242f:	66 90                	xchg   ax,ax
  102431:	66 90                	xchg   ax,ax
  102433:	66 90                	xchg   ax,ax
  102435:	66 90                	xchg   ax,ax
  102437:	66 90                	xchg   ax,ax
  102439:	66 90                	xchg   ax,ax
  10243b:	66 90                	xchg   ax,ax
  10243d:	66 90                	xchg   ax,ax
  10243f:	66 90                	xchg   ax,ax
  102441:	66 90                	xchg   ax,ax
  102443:	66 90                	xchg   ax,ax
  102445:	66 90                	xchg   ax,ax
  102447:	66 90                	xchg   ax,ax
  102449:	66 90                	xchg   ax,ax
  10244b:	66 90                	xchg   ax,ax
  10244d:	66 90                	xchg   ax,ax
  10244f:	66 90                	xchg   ax,ax
  102451:	66 90                	xchg   ax,ax
  102453:	66 90                	xchg   ax,ax
  102455:	66 90                	xchg   ax,ax
  102457:	66 90                	xchg   ax,ax
  102459:	66 90                	xchg   ax,ax
  10245b:	66 90                	xchg   ax,ax
  10245d:	66 90                	xchg   ax,ax
  10245f:	66 90                	xchg   ax,ax
  102461:	66 90                	xchg   ax,ax
  102463:	66 90                	xchg   ax,ax
  102465:	66 90                	xchg   ax,ax
  102467:	66 90                	xchg   ax,ax
  102469:	66 90                	xchg   ax,ax
  10246b:	66 90                	xchg   ax,ax
  10246d:	66 90                	xchg   ax,ax
  10246f:	66 90                	xchg   ax,ax
  102471:	66 90                	xchg   ax,ax
  102473:	66 90                	xchg   ax,ax
  102475:	66 90                	xchg   ax,ax
  102477:	66 90                	xchg   ax,ax
  102479:	66 90                	xchg   ax,ax
  10247b:	66 90                	xchg   ax,ax
  10247d:	66 90                	xchg   ax,ax
  10247f:	66 90                	xchg   ax,ax
  102481:	66 90                	xchg   ax,ax
  102483:	66 90                	xchg   ax,ax
  102485:	66 90                	xchg   ax,ax
  102487:	66 90                	xchg   ax,ax
  102489:	66 90                	xchg   ax,ax
  10248b:	66 90                	xchg   ax,ax
  10248d:	66 90                	xchg   ax,ax
  10248f:	66 90                	xchg   ax,ax
  102491:	66 90                	xchg   ax,ax
  102493:	66 90                	xchg   ax,ax
  102495:	66 90                	xchg   ax,ax
  102497:	66 90                	xchg   ax,ax
  102499:	66 90                	xchg   ax,ax
  10249b:	66 90                	xchg   ax,ax
  10249d:	66 90                	xchg   ax,ax
  10249f:	66 90                	xchg   ax,ax
  1024a1:	66 90                	xchg   ax,ax
  1024a3:	66 90                	xchg   ax,ax
  1024a5:	66 90                	xchg   ax,ax
  1024a7:	66 90                	xchg   ax,ax
  1024a9:	66 90                	xchg   ax,ax
  1024ab:	66 90                	xchg   ax,ax
  1024ad:	66 90                	xchg   ax,ax
  1024af:	66 90                	xchg   ax,ax
  1024b1:	66 90                	xchg   ax,ax
  1024b3:	66 90                	xchg   ax,ax
  1024b5:	66 90                	xchg   ax,ax
  1024b7:	66 90                	xchg   ax,ax
  1024b9:	66 90                	xchg   ax,ax
  1024bb:	66 90                	xchg   ax,ax
  1024bd:	66 90                	xchg   ax,ax
  1024bf:	66 90                	xchg   ax,ax
  1024c1:	66 90                	xchg   ax,ax
  1024c3:	66 90                	xchg   ax,ax
  1024c5:	66 90                	xchg   ax,ax
  1024c7:	66 90                	xchg   ax,ax
  1024c9:	66 90                	xchg   ax,ax
  1024cb:	66 90                	xchg   ax,ax
  1024cd:	66 90                	xchg   ax,ax
  1024cf:	66 90                	xchg   ax,ax
  1024d1:	66 90                	xchg   ax,ax
  1024d3:	66 90                	xchg   ax,ax
  1024d5:	66 90                	xchg   ax,ax
  1024d7:	66 90                	xchg   ax,ax
  1024d9:	66 90                	xchg   ax,ax
  1024db:	66 90                	xchg   ax,ax
  1024dd:	66 90                	xchg   ax,ax
  1024df:	66 90                	xchg   ax,ax
  1024e1:	66 90                	xchg   ax,ax
  1024e3:	66 90                	xchg   ax,ax
  1024e5:	66 90                	xchg   ax,ax
  1024e7:	66 90                	xchg   ax,ax
  1024e9:	66 90                	xchg   ax,ax
  1024eb:	66 90                	xchg   ax,ax
  1024ed:	66 90                	xchg   ax,ax
  1024ef:	66 90                	xchg   ax,ax
  1024f1:	66 90                	xchg   ax,ax
  1024f3:	66 90                	xchg   ax,ax
  1024f5:	66 90                	xchg   ax,ax
  1024f7:	66 90                	xchg   ax,ax
  1024f9:	66 90                	xchg   ax,ax
  1024fb:	66 90                	xchg   ax,ax
  1024fd:	66 90                	xchg   ax,ax
  1024ff:	66 90                	xchg   ax,ax
  102501:	66 90                	xchg   ax,ax
  102503:	66 90                	xchg   ax,ax
  102505:	66 90                	xchg   ax,ax
  102507:	66 90                	xchg   ax,ax
  102509:	66 90                	xchg   ax,ax
  10250b:	66 90                	xchg   ax,ax
  10250d:	66 90                	xchg   ax,ax
  10250f:	66 90                	xchg   ax,ax
  102511:	66 90                	xchg   ax,ax
  102513:	66 90                	xchg   ax,ax
  102515:	66 90                	xchg   ax,ax
  102517:	66 90                	xchg   ax,ax
  102519:	66 90                	xchg   ax,ax
  10251b:	66 90                	xchg   ax,ax
  10251d:	66 90                	xchg   ax,ax
  10251f:	66 90                	xchg   ax,ax
  102521:	66 90                	xchg   ax,ax
  102523:	66 90                	xchg   ax,ax
  102525:	66 90                	xchg   ax,ax
  102527:	66 90                	xchg   ax,ax
  102529:	66 90                	xchg   ax,ax
  10252b:	66 90                	xchg   ax,ax
  10252d:	66 90                	xchg   ax,ax
  10252f:	66 90                	xchg   ax,ax
  102531:	66 90                	xchg   ax,ax
  102533:	66 90                	xchg   ax,ax
  102535:	66 90                	xchg   ax,ax
  102537:	66 90                	xchg   ax,ax
  102539:	66 90                	xchg   ax,ax
  10253b:	66 90                	xchg   ax,ax
  10253d:	66 90                	xchg   ax,ax
  10253f:	66 90                	xchg   ax,ax
  102541:	66 90                	xchg   ax,ax
  102543:	66 90                	xchg   ax,ax
  102545:	66 90                	xchg   ax,ax
  102547:	66 90                	xchg   ax,ax
  102549:	66 90                	xchg   ax,ax
  10254b:	66 90                	xchg   ax,ax
  10254d:	66 90                	xchg   ax,ax
  10254f:	66 90                	xchg   ax,ax
  102551:	66 90                	xchg   ax,ax
  102553:	66 90                	xchg   ax,ax
  102555:	66 90                	xchg   ax,ax
  102557:	66 90                	xchg   ax,ax
  102559:	66 90                	xchg   ax,ax
  10255b:	66 90                	xchg   ax,ax
  10255d:	66 90                	xchg   ax,ax
  10255f:	66 90                	xchg   ax,ax
  102561:	66 90                	xchg   ax,ax
  102563:	66 90                	xchg   ax,ax
  102565:	66 90                	xchg   ax,ax
  102567:	66 90                	xchg   ax,ax
  102569:	66 90                	xchg   ax,ax
  10256b:	66 90                	xchg   ax,ax
  10256d:	66 90                	xchg   ax,ax
  10256f:	66 90                	xchg   ax,ax
  102571:	66 90                	xchg   ax,ax
  102573:	66 90                	xchg   ax,ax
  102575:	66 90                	xchg   ax,ax
  102577:	66 90                	xchg   ax,ax
  102579:	66 90                	xchg   ax,ax
  10257b:	66 90                	xchg   ax,ax
  10257d:	66 90                	xchg   ax,ax
  10257f:	66 90                	xchg   ax,ax
  102581:	66 90                	xchg   ax,ax
  102583:	66 90                	xchg   ax,ax
  102585:	66 90                	xchg   ax,ax
  102587:	66 90                	xchg   ax,ax
  102589:	66 90                	xchg   ax,ax
  10258b:	66 90                	xchg   ax,ax
  10258d:	66 90                	xchg   ax,ax
  10258f:	66 90                	xchg   ax,ax
  102591:	66 90                	xchg   ax,ax
  102593:	66 90                	xchg   ax,ax
  102595:	66 90                	xchg   ax,ax
  102597:	66 90                	xchg   ax,ax
  102599:	66 90                	xchg   ax,ax
  10259b:	66 90                	xchg   ax,ax
  10259d:	66 90                	xchg   ax,ax
  10259f:	66 90                	xchg   ax,ax
  1025a1:	66 90                	xchg   ax,ax
  1025a3:	66 90                	xchg   ax,ax
  1025a5:	66 90                	xchg   ax,ax
  1025a7:	66 90                	xchg   ax,ax
  1025a9:	66 90                	xchg   ax,ax
  1025ab:	66 90                	xchg   ax,ax
  1025ad:	66 90                	xchg   ax,ax
  1025af:	66 90                	xchg   ax,ax
  1025b1:	66 90                	xchg   ax,ax
  1025b3:	66 90                	xchg   ax,ax
  1025b5:	66 90                	xchg   ax,ax
  1025b7:	66 90                	xchg   ax,ax
  1025b9:	66 90                	xchg   ax,ax
  1025bb:	66 90                	xchg   ax,ax
  1025bd:	66 90                	xchg   ax,ax
  1025bf:	66 90                	xchg   ax,ax
  1025c1:	66 90                	xchg   ax,ax
  1025c3:	66 90                	xchg   ax,ax
  1025c5:	66 90                	xchg   ax,ax
  1025c7:	66 90                	xchg   ax,ax
  1025c9:	66 90                	xchg   ax,ax
  1025cb:	66 90                	xchg   ax,ax
  1025cd:	66 90                	xchg   ax,ax
  1025cf:	66 90                	xchg   ax,ax
  1025d1:	66 90                	xchg   ax,ax
  1025d3:	66 90                	xchg   ax,ax
  1025d5:	66 90                	xchg   ax,ax
  1025d7:	66 90                	xchg   ax,ax
  1025d9:	66 90                	xchg   ax,ax
  1025db:	66 90                	xchg   ax,ax
  1025dd:	66 90                	xchg   ax,ax
  1025df:	66 90                	xchg   ax,ax
  1025e1:	66 90                	xchg   ax,ax
  1025e3:	66 90                	xchg   ax,ax
  1025e5:	66 90                	xchg   ax,ax
  1025e7:	66 90                	xchg   ax,ax
  1025e9:	66 90                	xchg   ax,ax
  1025eb:	66 90                	xchg   ax,ax
  1025ed:	66 90                	xchg   ax,ax
  1025ef:	66 90                	xchg   ax,ax
  1025f1:	66 90                	xchg   ax,ax
  1025f3:	66 90                	xchg   ax,ax
  1025f5:	66 90                	xchg   ax,ax
  1025f7:	66 90                	xchg   ax,ax
  1025f9:	66 90                	xchg   ax,ax
  1025fb:	66 90                	xchg   ax,ax
  1025fd:	66 90                	xchg   ax,ax
  1025ff:	66 90                	xchg   ax,ax
  102601:	66 90                	xchg   ax,ax
  102603:	66 90                	xchg   ax,ax
  102605:	66 90                	xchg   ax,ax
  102607:	66 90                	xchg   ax,ax
  102609:	66 90                	xchg   ax,ax
  10260b:	66 90                	xchg   ax,ax
  10260d:	66 90                	xchg   ax,ax
  10260f:	66 90                	xchg   ax,ax
  102611:	66 90                	xchg   ax,ax
  102613:	66 90                	xchg   ax,ax
  102615:	66 90                	xchg   ax,ax
  102617:	66 90                	xchg   ax,ax
  102619:	66 90                	xchg   ax,ax
  10261b:	66 90                	xchg   ax,ax
  10261d:	66 90                	xchg   ax,ax
  10261f:	66 90                	xchg   ax,ax
  102621:	66 90                	xchg   ax,ax
  102623:	66 90                	xchg   ax,ax
  102625:	66 90                	xchg   ax,ax
  102627:	66 90                	xchg   ax,ax
  102629:	66 90                	xchg   ax,ax
  10262b:	66 90                	xchg   ax,ax
  10262d:	66 90                	xchg   ax,ax
  10262f:	66 90                	xchg   ax,ax
  102631:	66 90                	xchg   ax,ax
  102633:	66 90                	xchg   ax,ax
  102635:	66 90                	xchg   ax,ax
  102637:	66 90                	xchg   ax,ax
  102639:	66 90                	xchg   ax,ax
  10263b:	66 90                	xchg   ax,ax
  10263d:	66 90                	xchg   ax,ax
  10263f:	66 90                	xchg   ax,ax
  102641:	66 90                	xchg   ax,ax
  102643:	66 90                	xchg   ax,ax
  102645:	66 90                	xchg   ax,ax
  102647:	66 90                	xchg   ax,ax
  102649:	66 90                	xchg   ax,ax
  10264b:	66 90                	xchg   ax,ax
  10264d:	66 90                	xchg   ax,ax
  10264f:	66 90                	xchg   ax,ax
  102651:	66 90                	xchg   ax,ax
  102653:	66 90                	xchg   ax,ax
  102655:	66 90                	xchg   ax,ax
  102657:	66 90                	xchg   ax,ax
  102659:	66 90                	xchg   ax,ax
  10265b:	66 90                	xchg   ax,ax
  10265d:	66 90                	xchg   ax,ax
  10265f:	66 90                	xchg   ax,ax
  102661:	66 90                	xchg   ax,ax
  102663:	66 90                	xchg   ax,ax
  102665:	66 90                	xchg   ax,ax
  102667:	66 90                	xchg   ax,ax
  102669:	66 90                	xchg   ax,ax
  10266b:	66 90                	xchg   ax,ax
  10266d:	66 90                	xchg   ax,ax
  10266f:	66 90                	xchg   ax,ax
  102671:	66 90                	xchg   ax,ax
  102673:	66 90                	xchg   ax,ax
  102675:	66 90                	xchg   ax,ax
  102677:	66 90                	xchg   ax,ax
  102679:	66 90                	xchg   ax,ax
  10267b:	66 90                	xchg   ax,ax
  10267d:	66 90                	xchg   ax,ax
  10267f:	66 90                	xchg   ax,ax
  102681:	66 90                	xchg   ax,ax
  102683:	66 90                	xchg   ax,ax
  102685:	66 90                	xchg   ax,ax
  102687:	66 90                	xchg   ax,ax
  102689:	66 90                	xchg   ax,ax
  10268b:	66 90                	xchg   ax,ax
  10268d:	66 90                	xchg   ax,ax
  10268f:	66 90                	xchg   ax,ax
  102691:	66 90                	xchg   ax,ax
  102693:	66 90                	xchg   ax,ax
  102695:	66 90                	xchg   ax,ax
  102697:	66 90                	xchg   ax,ax
  102699:	66 90                	xchg   ax,ax
  10269b:	66 90                	xchg   ax,ax
  10269d:	66 90                	xchg   ax,ax
  10269f:	66 90                	xchg   ax,ax
  1026a1:	66 90                	xchg   ax,ax
  1026a3:	66 90                	xchg   ax,ax
  1026a5:	66 90                	xchg   ax,ax
  1026a7:	66 90                	xchg   ax,ax
  1026a9:	66 90                	xchg   ax,ax
  1026ab:	66 90                	xchg   ax,ax
  1026ad:	66 90                	xchg   ax,ax
  1026af:	66 90                	xchg   ax,ax
  1026b1:	66 90                	xchg   ax,ax
  1026b3:	66 90                	xchg   ax,ax
  1026b5:	66 90                	xchg   ax,ax
  1026b7:	66 90                	xchg   ax,ax
  1026b9:	66 90                	xchg   ax,ax
  1026bb:	66 90                	xchg   ax,ax
  1026bd:	66 90                	xchg   ax,ax
  1026bf:	66 90                	xchg   ax,ax
  1026c1:	66 90                	xchg   ax,ax
  1026c3:	66 90                	xchg   ax,ax
  1026c5:	66 90                	xchg   ax,ax
  1026c7:	66 90                	xchg   ax,ax
  1026c9:	66 90                	xchg   ax,ax
  1026cb:	66 90                	xchg   ax,ax
  1026cd:	66 90                	xchg   ax,ax
  1026cf:	66 90                	xchg   ax,ax
  1026d1:	66 90                	xchg   ax,ax
  1026d3:	66 90                	xchg   ax,ax
  1026d5:	66 90                	xchg   ax,ax
  1026d7:	66 90                	xchg   ax,ax
  1026d9:	66 90                	xchg   ax,ax
  1026db:	66 90                	xchg   ax,ax
  1026dd:	66 90                	xchg   ax,ax
  1026df:	66 90                	xchg   ax,ax
  1026e1:	66 90                	xchg   ax,ax
  1026e3:	66 90                	xchg   ax,ax
  1026e5:	66 90                	xchg   ax,ax
  1026e7:	66 90                	xchg   ax,ax
  1026e9:	66 90                	xchg   ax,ax
  1026eb:	66 90                	xchg   ax,ax
  1026ed:	66 90                	xchg   ax,ax
  1026ef:	66 90                	xchg   ax,ax
  1026f1:	66 90                	xchg   ax,ax
  1026f3:	66 90                	xchg   ax,ax
  1026f5:	66 90                	xchg   ax,ax
  1026f7:	66 90                	xchg   ax,ax
  1026f9:	66 90                	xchg   ax,ax
  1026fb:	66 90                	xchg   ax,ax
  1026fd:	66 90                	xchg   ax,ax
  1026ff:	66 90                	xchg   ax,ax
  102701:	66 90                	xchg   ax,ax
  102703:	66 90                	xchg   ax,ax
  102705:	66 90                	xchg   ax,ax
  102707:	66 90                	xchg   ax,ax
  102709:	66 90                	xchg   ax,ax
  10270b:	66 90                	xchg   ax,ax
  10270d:	66 90                	xchg   ax,ax
  10270f:	66 90                	xchg   ax,ax
  102711:	66 90                	xchg   ax,ax
  102713:	66 90                	xchg   ax,ax
  102715:	66 90                	xchg   ax,ax
  102717:	66 90                	xchg   ax,ax
  102719:	66 90                	xchg   ax,ax
  10271b:	66 90                	xchg   ax,ax
  10271d:	66 90                	xchg   ax,ax
  10271f:	66 90                	xchg   ax,ax
  102721:	66 90                	xchg   ax,ax
  102723:	66 90                	xchg   ax,ax
  102725:	66 90                	xchg   ax,ax
  102727:	66 90                	xchg   ax,ax
  102729:	66 90                	xchg   ax,ax
  10272b:	66 90                	xchg   ax,ax
  10272d:	66 90                	xchg   ax,ax
  10272f:	66 90                	xchg   ax,ax
  102731:	66 90                	xchg   ax,ax
  102733:	66 90                	xchg   ax,ax
  102735:	66 90                	xchg   ax,ax
  102737:	66 90                	xchg   ax,ax
  102739:	66 90                	xchg   ax,ax
  10273b:	66 90                	xchg   ax,ax
  10273d:	66 90                	xchg   ax,ax
  10273f:	66 90                	xchg   ax,ax
  102741:	66 90                	xchg   ax,ax
  102743:	66 90                	xchg   ax,ax
  102745:	66 90                	xchg   ax,ax
  102747:	66 90                	xchg   ax,ax
  102749:	66 90                	xchg   ax,ax
  10274b:	66 90                	xchg   ax,ax
  10274d:	66 90                	xchg   ax,ax
  10274f:	66 90                	xchg   ax,ax
  102751:	66 90                	xchg   ax,ax
  102753:	66 90                	xchg   ax,ax
  102755:	66 90                	xchg   ax,ax
  102757:	66 90                	xchg   ax,ax
  102759:	66 90                	xchg   ax,ax
  10275b:	66 90                	xchg   ax,ax
  10275d:	66 90                	xchg   ax,ax
  10275f:	66 90                	xchg   ax,ax
  102761:	66 90                	xchg   ax,ax
  102763:	66 90                	xchg   ax,ax
  102765:	66 90                	xchg   ax,ax
  102767:	66 90                	xchg   ax,ax
  102769:	66 90                	xchg   ax,ax
  10276b:	66 90                	xchg   ax,ax
  10276d:	66 90                	xchg   ax,ax
  10276f:	66 90                	xchg   ax,ax
  102771:	66 90                	xchg   ax,ax
  102773:	66 90                	xchg   ax,ax
  102775:	66 90                	xchg   ax,ax
  102777:	66 90                	xchg   ax,ax
  102779:	66 90                	xchg   ax,ax
  10277b:	66 90                	xchg   ax,ax
  10277d:	66 90                	xchg   ax,ax
  10277f:	66 90                	xchg   ax,ax
  102781:	66 90                	xchg   ax,ax
  102783:	66 90                	xchg   ax,ax
  102785:	66 90                	xchg   ax,ax
  102787:	66 90                	xchg   ax,ax
  102789:	66 90                	xchg   ax,ax
  10278b:	66 90                	xchg   ax,ax
  10278d:	66 90                	xchg   ax,ax
  10278f:	66 90                	xchg   ax,ax
  102791:	66 90                	xchg   ax,ax
  102793:	66 90                	xchg   ax,ax
  102795:	66 90                	xchg   ax,ax
  102797:	66 90                	xchg   ax,ax
  102799:	66 90                	xchg   ax,ax
  10279b:	66 90                	xchg   ax,ax
  10279d:	66 90                	xchg   ax,ax
  10279f:	66 90                	xchg   ax,ax
  1027a1:	66 90                	xchg   ax,ax
  1027a3:	66 90                	xchg   ax,ax
  1027a5:	66 90                	xchg   ax,ax
  1027a7:	66 90                	xchg   ax,ax
  1027a9:	66 90                	xchg   ax,ax
  1027ab:	66 90                	xchg   ax,ax
  1027ad:	66 90                	xchg   ax,ax
  1027af:	66 90                	xchg   ax,ax
  1027b1:	66 90                	xchg   ax,ax
  1027b3:	66 90                	xchg   ax,ax
  1027b5:	66 90                	xchg   ax,ax
  1027b7:	66 90                	xchg   ax,ax
  1027b9:	66 90                	xchg   ax,ax
  1027bb:	66 90                	xchg   ax,ax
  1027bd:	66 90                	xchg   ax,ax
  1027bf:	66 90                	xchg   ax,ax
  1027c1:	66 90                	xchg   ax,ax
  1027c3:	66 90                	xchg   ax,ax
  1027c5:	66 90                	xchg   ax,ax
  1027c7:	66 90                	xchg   ax,ax
  1027c9:	66 90                	xchg   ax,ax
  1027cb:	66 90                	xchg   ax,ax
  1027cd:	66 90                	xchg   ax,ax
  1027cf:	66 90                	xchg   ax,ax
  1027d1:	66 90                	xchg   ax,ax
  1027d3:	66 90                	xchg   ax,ax
  1027d5:	66 90                	xchg   ax,ax
  1027d7:	66 90                	xchg   ax,ax
  1027d9:	66 90                	xchg   ax,ax
  1027db:	66 90                	xchg   ax,ax
  1027dd:	66 90                	xchg   ax,ax
  1027df:	66 90                	xchg   ax,ax
  1027e1:	66 90                	xchg   ax,ax
  1027e3:	66 90                	xchg   ax,ax
  1027e5:	66 90                	xchg   ax,ax
  1027e7:	66 90                	xchg   ax,ax
  1027e9:	66 90                	xchg   ax,ax
  1027eb:	66 90                	xchg   ax,ax
  1027ed:	66 90                	xchg   ax,ax
  1027ef:	66 90                	xchg   ax,ax
  1027f1:	66 90                	xchg   ax,ax
  1027f3:	66 90                	xchg   ax,ax
  1027f5:	66 90                	xchg   ax,ax
  1027f7:	66 90                	xchg   ax,ax
  1027f9:	66 90                	xchg   ax,ax
  1027fb:	66 90                	xchg   ax,ax
  1027fd:	66 90                	xchg   ax,ax
  1027ff:	66 90                	xchg   ax,ax
  102801:	66 90                	xchg   ax,ax
  102803:	66 90                	xchg   ax,ax
  102805:	66 90                	xchg   ax,ax
  102807:	66 90                	xchg   ax,ax
  102809:	66 90                	xchg   ax,ax
  10280b:	66 90                	xchg   ax,ax
  10280d:	66 90                	xchg   ax,ax
  10280f:	66 90                	xchg   ax,ax
  102811:	66 90                	xchg   ax,ax
  102813:	66 90                	xchg   ax,ax
  102815:	66 90                	xchg   ax,ax
  102817:	66 90                	xchg   ax,ax
  102819:	66 90                	xchg   ax,ax
  10281b:	66 90                	xchg   ax,ax
  10281d:	66 90                	xchg   ax,ax
  10281f:	66 90                	xchg   ax,ax
  102821:	66 90                	xchg   ax,ax
  102823:	66 90                	xchg   ax,ax
  102825:	66 90                	xchg   ax,ax
  102827:	66 90                	xchg   ax,ax
  102829:	66 90                	xchg   ax,ax
  10282b:	66 90                	xchg   ax,ax
  10282d:	66 90                	xchg   ax,ax
  10282f:	66 90                	xchg   ax,ax
  102831:	66 90                	xchg   ax,ax
  102833:	66 90                	xchg   ax,ax
  102835:	66 90                	xchg   ax,ax
  102837:	66 90                	xchg   ax,ax
  102839:	66 90                	xchg   ax,ax
  10283b:	66 90                	xchg   ax,ax
  10283d:	66 90                	xchg   ax,ax
  10283f:	66 90                	xchg   ax,ax
  102841:	66 90                	xchg   ax,ax
  102843:	66 90                	xchg   ax,ax
  102845:	66 90                	xchg   ax,ax
  102847:	66 90                	xchg   ax,ax
  102849:	66 90                	xchg   ax,ax
  10284b:	66 90                	xchg   ax,ax
  10284d:	66 90                	xchg   ax,ax
  10284f:	66 90                	xchg   ax,ax
  102851:	66 90                	xchg   ax,ax
  102853:	66 90                	xchg   ax,ax
  102855:	66 90                	xchg   ax,ax
  102857:	66 90                	xchg   ax,ax
  102859:	66 90                	xchg   ax,ax
  10285b:	66 90                	xchg   ax,ax
  10285d:	66 90                	xchg   ax,ax
  10285f:	66 90                	xchg   ax,ax
  102861:	66 90                	xchg   ax,ax
  102863:	66 90                	xchg   ax,ax
  102865:	66 90                	xchg   ax,ax
  102867:	66 90                	xchg   ax,ax
  102869:	66 90                	xchg   ax,ax
  10286b:	66 90                	xchg   ax,ax
  10286d:	66 90                	xchg   ax,ax
  10286f:	66 90                	xchg   ax,ax
  102871:	66 90                	xchg   ax,ax
  102873:	66 90                	xchg   ax,ax
  102875:	66 90                	xchg   ax,ax
  102877:	66 90                	xchg   ax,ax
  102879:	66 90                	xchg   ax,ax
  10287b:	66 90                	xchg   ax,ax
  10287d:	66 90                	xchg   ax,ax
  10287f:	66 90                	xchg   ax,ax
  102881:	66 90                	xchg   ax,ax
  102883:	66 90                	xchg   ax,ax
  102885:	66 90                	xchg   ax,ax
  102887:	66 90                	xchg   ax,ax
  102889:	66 90                	xchg   ax,ax
  10288b:	66 90                	xchg   ax,ax
  10288d:	66 90                	xchg   ax,ax
  10288f:	66 90                	xchg   ax,ax
  102891:	66 90                	xchg   ax,ax
  102893:	66 90                	xchg   ax,ax
  102895:	66 90                	xchg   ax,ax
  102897:	66 90                	xchg   ax,ax
  102899:	66 90                	xchg   ax,ax
  10289b:	66 90                	xchg   ax,ax
  10289d:	66 90                	xchg   ax,ax
  10289f:	66 90                	xchg   ax,ax
  1028a1:	66 90                	xchg   ax,ax
  1028a3:	66 90                	xchg   ax,ax
  1028a5:	66 90                	xchg   ax,ax
  1028a7:	66 90                	xchg   ax,ax
  1028a9:	66 90                	xchg   ax,ax
  1028ab:	66 90                	xchg   ax,ax
  1028ad:	66 90                	xchg   ax,ax
  1028af:	66 90                	xchg   ax,ax
  1028b1:	66 90                	xchg   ax,ax
  1028b3:	66 90                	xchg   ax,ax
  1028b5:	66 90                	xchg   ax,ax
  1028b7:	66 90                	xchg   ax,ax
  1028b9:	66 90                	xchg   ax,ax
  1028bb:	66 90                	xchg   ax,ax
  1028bd:	66 90                	xchg   ax,ax
  1028bf:	66 90                	xchg   ax,ax
  1028c1:	66 90                	xchg   ax,ax
  1028c3:	66 90                	xchg   ax,ax
  1028c5:	66 90                	xchg   ax,ax
  1028c7:	66 90                	xchg   ax,ax
  1028c9:	66 90                	xchg   ax,ax
  1028cb:	66 90                	xchg   ax,ax
  1028cd:	66 90                	xchg   ax,ax
  1028cf:	66 90                	xchg   ax,ax
  1028d1:	66 90                	xchg   ax,ax
  1028d3:	66 90                	xchg   ax,ax
  1028d5:	66 90                	xchg   ax,ax
  1028d7:	66 90                	xchg   ax,ax
  1028d9:	66 90                	xchg   ax,ax
  1028db:	66 90                	xchg   ax,ax
  1028dd:	66 90                	xchg   ax,ax
  1028df:	66 90                	xchg   ax,ax
  1028e1:	66 90                	xchg   ax,ax
  1028e3:	66 90                	xchg   ax,ax
  1028e5:	66 90                	xchg   ax,ax
  1028e7:	66 90                	xchg   ax,ax
  1028e9:	66 90                	xchg   ax,ax
  1028eb:	66 90                	xchg   ax,ax
  1028ed:	66 90                	xchg   ax,ax
  1028ef:	66 90                	xchg   ax,ax
  1028f1:	66 90                	xchg   ax,ax
  1028f3:	66 90                	xchg   ax,ax
  1028f5:	66 90                	xchg   ax,ax
  1028f7:	66 90                	xchg   ax,ax
  1028f9:	66 90                	xchg   ax,ax
  1028fb:	66 90                	xchg   ax,ax
  1028fd:	66 90                	xchg   ax,ax
  1028ff:	66 90                	xchg   ax,ax
  102901:	66 90                	xchg   ax,ax
  102903:	66 90                	xchg   ax,ax
  102905:	66 90                	xchg   ax,ax
  102907:	66 90                	xchg   ax,ax
  102909:	66 90                	xchg   ax,ax
  10290b:	66 90                	xchg   ax,ax
  10290d:	66 90                	xchg   ax,ax
  10290f:	66 90                	xchg   ax,ax
  102911:	66 90                	xchg   ax,ax
  102913:	66 90                	xchg   ax,ax
  102915:	66 90                	xchg   ax,ax
  102917:	66 90                	xchg   ax,ax
  102919:	66 90                	xchg   ax,ax
  10291b:	66 90                	xchg   ax,ax
  10291d:	66 90                	xchg   ax,ax
  10291f:	66 90                	xchg   ax,ax
  102921:	66 90                	xchg   ax,ax
  102923:	66 90                	xchg   ax,ax
  102925:	66 90                	xchg   ax,ax
  102927:	66 90                	xchg   ax,ax
  102929:	66 90                	xchg   ax,ax
  10292b:	66 90                	xchg   ax,ax
  10292d:	66 90                	xchg   ax,ax
  10292f:	66 90                	xchg   ax,ax
  102931:	66 90                	xchg   ax,ax
  102933:	66 90                	xchg   ax,ax
  102935:	66 90                	xchg   ax,ax
  102937:	66 90                	xchg   ax,ax
  102939:	66 90                	xchg   ax,ax
  10293b:	66 90                	xchg   ax,ax
  10293d:	66 90                	xchg   ax,ax
  10293f:	66 90                	xchg   ax,ax
  102941:	66 90                	xchg   ax,ax
  102943:	66 90                	xchg   ax,ax
  102945:	66 90                	xchg   ax,ax
  102947:	66 90                	xchg   ax,ax
  102949:	66 90                	xchg   ax,ax
  10294b:	66 90                	xchg   ax,ax
  10294d:	66 90                	xchg   ax,ax
  10294f:	66 90                	xchg   ax,ax
  102951:	66 90                	xchg   ax,ax
  102953:	66 90                	xchg   ax,ax
  102955:	66 90                	xchg   ax,ax
  102957:	66 90                	xchg   ax,ax
  102959:	66 90                	xchg   ax,ax
  10295b:	66 90                	xchg   ax,ax
  10295d:	66 90                	xchg   ax,ax
  10295f:	66 90                	xchg   ax,ax
  102961:	66 90                	xchg   ax,ax
  102963:	66 90                	xchg   ax,ax
  102965:	66 90                	xchg   ax,ax
  102967:	66 90                	xchg   ax,ax
  102969:	66 90                	xchg   ax,ax
  10296b:	66 90                	xchg   ax,ax
  10296d:	66 90                	xchg   ax,ax
  10296f:	66 90                	xchg   ax,ax
  102971:	66 90                	xchg   ax,ax
  102973:	66 90                	xchg   ax,ax
  102975:	66 90                	xchg   ax,ax
  102977:	66 90                	xchg   ax,ax
  102979:	66 90                	xchg   ax,ax
  10297b:	66 90                	xchg   ax,ax
  10297d:	66 90                	xchg   ax,ax
  10297f:	66 90                	xchg   ax,ax
  102981:	66 90                	xchg   ax,ax
  102983:	66 90                	xchg   ax,ax
  102985:	66 90                	xchg   ax,ax
  102987:	66 90                	xchg   ax,ax
  102989:	66 90                	xchg   ax,ax
  10298b:	66 90                	xchg   ax,ax
  10298d:	66 90                	xchg   ax,ax
  10298f:	66 90                	xchg   ax,ax
  102991:	66 90                	xchg   ax,ax
  102993:	66 90                	xchg   ax,ax
  102995:	66 90                	xchg   ax,ax
  102997:	66 90                	xchg   ax,ax
  102999:	66 90                	xchg   ax,ax
  10299b:	66 90                	xchg   ax,ax
  10299d:	66 90                	xchg   ax,ax
  10299f:	66 90                	xchg   ax,ax
  1029a1:	66 90                	xchg   ax,ax
  1029a3:	66 90                	xchg   ax,ax
  1029a5:	66 90                	xchg   ax,ax
  1029a7:	66 90                	xchg   ax,ax
  1029a9:	66 90                	xchg   ax,ax
  1029ab:	66 90                	xchg   ax,ax
  1029ad:	66 90                	xchg   ax,ax
  1029af:	66 90                	xchg   ax,ax
  1029b1:	66 90                	xchg   ax,ax
  1029b3:	66 90                	xchg   ax,ax
  1029b5:	66 90                	xchg   ax,ax
  1029b7:	66 90                	xchg   ax,ax
  1029b9:	66 90                	xchg   ax,ax
  1029bb:	66 90                	xchg   ax,ax
  1029bd:	66 90                	xchg   ax,ax
  1029bf:	66 90                	xchg   ax,ax
  1029c1:	66 90                	xchg   ax,ax
  1029c3:	66 90                	xchg   ax,ax
  1029c5:	66 90                	xchg   ax,ax
  1029c7:	66 90                	xchg   ax,ax
  1029c9:	66 90                	xchg   ax,ax
  1029cb:	66 90                	xchg   ax,ax
  1029cd:	66 90                	xchg   ax,ax
  1029cf:	66 90                	xchg   ax,ax
  1029d1:	66 90                	xchg   ax,ax
  1029d3:	66 90                	xchg   ax,ax
  1029d5:	66 90                	xchg   ax,ax
  1029d7:	66 90                	xchg   ax,ax
  1029d9:	66 90                	xchg   ax,ax
  1029db:	66 90                	xchg   ax,ax
  1029dd:	66 90                	xchg   ax,ax
  1029df:	66 90                	xchg   ax,ax
  1029e1:	66 90                	xchg   ax,ax
  1029e3:	66 90                	xchg   ax,ax
  1029e5:	66 90                	xchg   ax,ax
  1029e7:	66 90                	xchg   ax,ax
  1029e9:	66 90                	xchg   ax,ax
  1029eb:	66 90                	xchg   ax,ax
  1029ed:	66 90                	xchg   ax,ax
  1029ef:	66 90                	xchg   ax,ax
  1029f1:	66 90                	xchg   ax,ax
  1029f3:	66 90                	xchg   ax,ax
  1029f5:	66 90                	xchg   ax,ax
  1029f7:	66 90                	xchg   ax,ax
  1029f9:	66 90                	xchg   ax,ax
  1029fb:	66 90                	xchg   ax,ax
  1029fd:	66 90                	xchg   ax,ax
  1029ff:	66 90                	xchg   ax,ax
  102a01:	66 90                	xchg   ax,ax
  102a03:	66 90                	xchg   ax,ax
  102a05:	66 90                	xchg   ax,ax
  102a07:	66 90                	xchg   ax,ax
  102a09:	66 90                	xchg   ax,ax
  102a0b:	66 90                	xchg   ax,ax
  102a0d:	66 90                	xchg   ax,ax
  102a0f:	66 90                	xchg   ax,ax
  102a11:	66 90                	xchg   ax,ax
  102a13:	66 90                	xchg   ax,ax
  102a15:	66 90                	xchg   ax,ax
  102a17:	66 90                	xchg   ax,ax
  102a19:	66 90                	xchg   ax,ax
  102a1b:	66 90                	xchg   ax,ax
  102a1d:	66 90                	xchg   ax,ax
  102a1f:	66 90                	xchg   ax,ax
  102a21:	66 90                	xchg   ax,ax
  102a23:	66 90                	xchg   ax,ax
  102a25:	66 90                	xchg   ax,ax
  102a27:	66 90                	xchg   ax,ax
  102a29:	66 90                	xchg   ax,ax
  102a2b:	66 90                	xchg   ax,ax
  102a2d:	66 90                	xchg   ax,ax
  102a2f:	66 90                	xchg   ax,ax
  102a31:	66 90                	xchg   ax,ax
  102a33:	66 90                	xchg   ax,ax
  102a35:	66 90                	xchg   ax,ax
  102a37:	66 90                	xchg   ax,ax
  102a39:	66 90                	xchg   ax,ax
  102a3b:	66 90                	xchg   ax,ax
  102a3d:	66 90                	xchg   ax,ax
  102a3f:	66 90                	xchg   ax,ax
  102a41:	66 90                	xchg   ax,ax
  102a43:	66 90                	xchg   ax,ax
  102a45:	66 90                	xchg   ax,ax
  102a47:	66 90                	xchg   ax,ax
  102a49:	66 90                	xchg   ax,ax
  102a4b:	66 90                	xchg   ax,ax
  102a4d:	66 90                	xchg   ax,ax
  102a4f:	66 90                	xchg   ax,ax
  102a51:	66 90                	xchg   ax,ax
  102a53:	66 90                	xchg   ax,ax
  102a55:	66 90                	xchg   ax,ax
  102a57:	66 90                	xchg   ax,ax
  102a59:	66 90                	xchg   ax,ax
  102a5b:	66 90                	xchg   ax,ax
  102a5d:	66 90                	xchg   ax,ax
  102a5f:	66 90                	xchg   ax,ax
  102a61:	66 90                	xchg   ax,ax
  102a63:	66 90                	xchg   ax,ax
  102a65:	66 90                	xchg   ax,ax
  102a67:	66 90                	xchg   ax,ax
  102a69:	66 90                	xchg   ax,ax
  102a6b:	66 90                	xchg   ax,ax
  102a6d:	66 90                	xchg   ax,ax
  102a6f:	66 90                	xchg   ax,ax
  102a71:	66 90                	xchg   ax,ax
  102a73:	66 90                	xchg   ax,ax
  102a75:	66 90                	xchg   ax,ax
  102a77:	66 90                	xchg   ax,ax
  102a79:	66 90                	xchg   ax,ax
  102a7b:	66 90                	xchg   ax,ax
  102a7d:	66 90                	xchg   ax,ax
  102a7f:	66 90                	xchg   ax,ax
  102a81:	66 90                	xchg   ax,ax
  102a83:	66 90                	xchg   ax,ax
  102a85:	66 90                	xchg   ax,ax
  102a87:	66 90                	xchg   ax,ax
  102a89:	66 90                	xchg   ax,ax
  102a8b:	66 90                	xchg   ax,ax
  102a8d:	66 90                	xchg   ax,ax
  102a8f:	66 90                	xchg   ax,ax
  102a91:	66 90                	xchg   ax,ax
  102a93:	66 90                	xchg   ax,ax
  102a95:	66 90                	xchg   ax,ax
  102a97:	66 90                	xchg   ax,ax
  102a99:	66 90                	xchg   ax,ax
  102a9b:	66 90                	xchg   ax,ax
  102a9d:	66 90                	xchg   ax,ax
  102a9f:	66 90                	xchg   ax,ax
  102aa1:	66 90                	xchg   ax,ax
  102aa3:	66 90                	xchg   ax,ax
  102aa5:	66 90                	xchg   ax,ax
  102aa7:	66 90                	xchg   ax,ax
  102aa9:	66 90                	xchg   ax,ax
  102aab:	66 90                	xchg   ax,ax
  102aad:	66 90                	xchg   ax,ax
  102aaf:	66 90                	xchg   ax,ax
  102ab1:	66 90                	xchg   ax,ax
  102ab3:	66 90                	xchg   ax,ax
  102ab5:	66 90                	xchg   ax,ax
  102ab7:	66 90                	xchg   ax,ax
  102ab9:	66 90                	xchg   ax,ax
  102abb:	66 90                	xchg   ax,ax
  102abd:	66 90                	xchg   ax,ax
  102abf:	66 90                	xchg   ax,ax
  102ac1:	66 90                	xchg   ax,ax
  102ac3:	66 90                	xchg   ax,ax
  102ac5:	66 90                	xchg   ax,ax
  102ac7:	66 90                	xchg   ax,ax
  102ac9:	66 90                	xchg   ax,ax
  102acb:	66 90                	xchg   ax,ax
  102acd:	66 90                	xchg   ax,ax
  102acf:	66 90                	xchg   ax,ax
  102ad1:	66 90                	xchg   ax,ax
  102ad3:	66 90                	xchg   ax,ax
  102ad5:	66 90                	xchg   ax,ax
  102ad7:	66 90                	xchg   ax,ax
  102ad9:	66 90                	xchg   ax,ax
  102adb:	66 90                	xchg   ax,ax
  102add:	66 90                	xchg   ax,ax
  102adf:	66 90                	xchg   ax,ax
  102ae1:	66 90                	xchg   ax,ax
  102ae3:	66 90                	xchg   ax,ax
  102ae5:	66 90                	xchg   ax,ax
  102ae7:	66 90                	xchg   ax,ax
  102ae9:	66 90                	xchg   ax,ax
  102aeb:	66 90                	xchg   ax,ax
  102aed:	66 90                	xchg   ax,ax
  102aef:	66 90                	xchg   ax,ax
  102af1:	66 90                	xchg   ax,ax
  102af3:	66 90                	xchg   ax,ax
  102af5:	66 90                	xchg   ax,ax
  102af7:	66 90                	xchg   ax,ax
  102af9:	66 90                	xchg   ax,ax
  102afb:	66 90                	xchg   ax,ax
  102afd:	66 90                	xchg   ax,ax
  102aff:	66 90                	xchg   ax,ax
  102b01:	66 90                	xchg   ax,ax
  102b03:	66 90                	xchg   ax,ax
  102b05:	66 90                	xchg   ax,ax
  102b07:	66 90                	xchg   ax,ax
  102b09:	66 90                	xchg   ax,ax
  102b0b:	66 90                	xchg   ax,ax
  102b0d:	66 90                	xchg   ax,ax
  102b0f:	66 90                	xchg   ax,ax
  102b11:	66 90                	xchg   ax,ax
  102b13:	66 90                	xchg   ax,ax
  102b15:	66 90                	xchg   ax,ax
  102b17:	66 90                	xchg   ax,ax
  102b19:	66 90                	xchg   ax,ax
  102b1b:	66 90                	xchg   ax,ax
  102b1d:	66 90                	xchg   ax,ax
  102b1f:	66 90                	xchg   ax,ax
  102b21:	66 90                	xchg   ax,ax
  102b23:	66 90                	xchg   ax,ax
  102b25:	66 90                	xchg   ax,ax
  102b27:	66 90                	xchg   ax,ax
  102b29:	66 90                	xchg   ax,ax
  102b2b:	66 90                	xchg   ax,ax
  102b2d:	66 90                	xchg   ax,ax
  102b2f:	66 90                	xchg   ax,ax
  102b31:	66 90                	xchg   ax,ax
  102b33:	66 90                	xchg   ax,ax
  102b35:	66 90                	xchg   ax,ax
  102b37:	66 90                	xchg   ax,ax
  102b39:	66 90                	xchg   ax,ax
  102b3b:	66 90                	xchg   ax,ax
  102b3d:	66 90                	xchg   ax,ax
  102b3f:	66 90                	xchg   ax,ax
  102b41:	66 90                	xchg   ax,ax
  102b43:	66 90                	xchg   ax,ax
  102b45:	66 90                	xchg   ax,ax
  102b47:	66 90                	xchg   ax,ax
  102b49:	66 90                	xchg   ax,ax
  102b4b:	66 90                	xchg   ax,ax
  102b4d:	66 90                	xchg   ax,ax
  102b4f:	66 90                	xchg   ax,ax
  102b51:	66 90                	xchg   ax,ax
  102b53:	66 90                	xchg   ax,ax
  102b55:	66 90                	xchg   ax,ax
  102b57:	66 90                	xchg   ax,ax
  102b59:	66 90                	xchg   ax,ax
  102b5b:	66 90                	xchg   ax,ax
  102b5d:	66 90                	xchg   ax,ax
  102b5f:	66 90                	xchg   ax,ax
  102b61:	66 90                	xchg   ax,ax
  102b63:	66 90                	xchg   ax,ax
  102b65:	66 90                	xchg   ax,ax
  102b67:	66 90                	xchg   ax,ax
  102b69:	66 90                	xchg   ax,ax
  102b6b:	66 90                	xchg   ax,ax
  102b6d:	66 90                	xchg   ax,ax
  102b6f:	66 90                	xchg   ax,ax
  102b71:	66 90                	xchg   ax,ax
  102b73:	66 90                	xchg   ax,ax
  102b75:	66 90                	xchg   ax,ax
  102b77:	66 90                	xchg   ax,ax
  102b79:	66 90                	xchg   ax,ax
  102b7b:	66 90                	xchg   ax,ax
  102b7d:	66 90                	xchg   ax,ax
  102b7f:	66 90                	xchg   ax,ax
  102b81:	66 90                	xchg   ax,ax
  102b83:	66 90                	xchg   ax,ax
  102b85:	66 90                	xchg   ax,ax
  102b87:	66 90                	xchg   ax,ax
  102b89:	66 90                	xchg   ax,ax
  102b8b:	66 90                	xchg   ax,ax
  102b8d:	66 90                	xchg   ax,ax
  102b8f:	66 90                	xchg   ax,ax
  102b91:	66 90                	xchg   ax,ax
  102b93:	66 90                	xchg   ax,ax
  102b95:	66 90                	xchg   ax,ax
  102b97:	66 90                	xchg   ax,ax
  102b99:	66 90                	xchg   ax,ax
  102b9b:	66 90                	xchg   ax,ax
  102b9d:	66 90                	xchg   ax,ax
  102b9f:	66 90                	xchg   ax,ax
  102ba1:	66 90                	xchg   ax,ax
  102ba3:	66 90                	xchg   ax,ax
  102ba5:	66 90                	xchg   ax,ax
  102ba7:	66 90                	xchg   ax,ax
  102ba9:	66 90                	xchg   ax,ax
  102bab:	66 90                	xchg   ax,ax
  102bad:	66 90                	xchg   ax,ax
  102baf:	66 90                	xchg   ax,ax
  102bb1:	66 90                	xchg   ax,ax
  102bb3:	66 90                	xchg   ax,ax
  102bb5:	66 90                	xchg   ax,ax
  102bb7:	66 90                	xchg   ax,ax
  102bb9:	66 90                	xchg   ax,ax
  102bbb:	66 90                	xchg   ax,ax
  102bbd:	66 90                	xchg   ax,ax
  102bbf:	66 90                	xchg   ax,ax
  102bc1:	66 90                	xchg   ax,ax
  102bc3:	66 90                	xchg   ax,ax
  102bc5:	66 90                	xchg   ax,ax
  102bc7:	66 90                	xchg   ax,ax
  102bc9:	66 90                	xchg   ax,ax
  102bcb:	66 90                	xchg   ax,ax
  102bcd:	66 90                	xchg   ax,ax
  102bcf:	66 90                	xchg   ax,ax
  102bd1:	66 90                	xchg   ax,ax
  102bd3:	66 90                	xchg   ax,ax
  102bd5:	66 90                	xchg   ax,ax
  102bd7:	66 90                	xchg   ax,ax
  102bd9:	66 90                	xchg   ax,ax
  102bdb:	66 90                	xchg   ax,ax
  102bdd:	66 90                	xchg   ax,ax
  102bdf:	66 90                	xchg   ax,ax
  102be1:	66 90                	xchg   ax,ax
  102be3:	66 90                	xchg   ax,ax
  102be5:	66 90                	xchg   ax,ax
  102be7:	66 90                	xchg   ax,ax
  102be9:	66 90                	xchg   ax,ax
  102beb:	66 90                	xchg   ax,ax
  102bed:	66 90                	xchg   ax,ax
  102bef:	66 90                	xchg   ax,ax
  102bf1:	66 90                	xchg   ax,ax
  102bf3:	66 90                	xchg   ax,ax
  102bf5:	66 90                	xchg   ax,ax
  102bf7:	66 90                	xchg   ax,ax
  102bf9:	66 90                	xchg   ax,ax
  102bfb:	66 90                	xchg   ax,ax
  102bfd:	66 90                	xchg   ax,ax
  102bff:	66 90                	xchg   ax,ax
  102c01:	66 90                	xchg   ax,ax
  102c03:	66 90                	xchg   ax,ax
  102c05:	66 90                	xchg   ax,ax
  102c07:	66 90                	xchg   ax,ax
  102c09:	66 90                	xchg   ax,ax
  102c0b:	66 90                	xchg   ax,ax
  102c0d:	66 90                	xchg   ax,ax
  102c0f:	66 90                	xchg   ax,ax
  102c11:	66 90                	xchg   ax,ax
  102c13:	66 90                	xchg   ax,ax
  102c15:	66 90                	xchg   ax,ax
  102c17:	66 90                	xchg   ax,ax
  102c19:	66 90                	xchg   ax,ax
  102c1b:	66 90                	xchg   ax,ax
  102c1d:	66 90                	xchg   ax,ax
  102c1f:	66 90                	xchg   ax,ax
  102c21:	66 90                	xchg   ax,ax
  102c23:	66 90                	xchg   ax,ax
  102c25:	66 90                	xchg   ax,ax
  102c27:	66 90                	xchg   ax,ax
  102c29:	66 90                	xchg   ax,ax
  102c2b:	66 90                	xchg   ax,ax
  102c2d:	66 90                	xchg   ax,ax
  102c2f:	66 90                	xchg   ax,ax
  102c31:	66 90                	xchg   ax,ax
  102c33:	66 90                	xchg   ax,ax
  102c35:	66 90                	xchg   ax,ax
  102c37:	66 90                	xchg   ax,ax
  102c39:	66 90                	xchg   ax,ax
  102c3b:	66 90                	xchg   ax,ax
  102c3d:	66 90                	xchg   ax,ax
  102c3f:	66 90                	xchg   ax,ax
  102c41:	66 90                	xchg   ax,ax
  102c43:	66 90                	xchg   ax,ax
  102c45:	66 90                	xchg   ax,ax
  102c47:	66 90                	xchg   ax,ax
  102c49:	66 90                	xchg   ax,ax
  102c4b:	66 90                	xchg   ax,ax
  102c4d:	66 90                	xchg   ax,ax
  102c4f:	66 90                	xchg   ax,ax
  102c51:	66 90                	xchg   ax,ax
  102c53:	66 90                	xchg   ax,ax
  102c55:	66 90                	xchg   ax,ax
  102c57:	66 90                	xchg   ax,ax
  102c59:	66 90                	xchg   ax,ax
  102c5b:	66 90                	xchg   ax,ax
  102c5d:	66 90                	xchg   ax,ax
  102c5f:	66 90                	xchg   ax,ax
  102c61:	66 90                	xchg   ax,ax
  102c63:	66 90                	xchg   ax,ax
  102c65:	66 90                	xchg   ax,ax
  102c67:	66 90                	xchg   ax,ax
  102c69:	66 90                	xchg   ax,ax
  102c6b:	66 90                	xchg   ax,ax
  102c6d:	66 90                	xchg   ax,ax
  102c6f:	66 90                	xchg   ax,ax
  102c71:	66 90                	xchg   ax,ax
  102c73:	66 90                	xchg   ax,ax
  102c75:	66 90                	xchg   ax,ax
  102c77:	66 90                	xchg   ax,ax
  102c79:	66 90                	xchg   ax,ax
  102c7b:	66 90                	xchg   ax,ax
  102c7d:	66 90                	xchg   ax,ax
  102c7f:	66 90                	xchg   ax,ax
  102c81:	66 90                	xchg   ax,ax
  102c83:	66 90                	xchg   ax,ax
  102c85:	66 90                	xchg   ax,ax
  102c87:	66 90                	xchg   ax,ax
  102c89:	66 90                	xchg   ax,ax
  102c8b:	66 90                	xchg   ax,ax
  102c8d:	66 90                	xchg   ax,ax
  102c8f:	66 90                	xchg   ax,ax
  102c91:	66 90                	xchg   ax,ax
  102c93:	66 90                	xchg   ax,ax
  102c95:	66 90                	xchg   ax,ax
  102c97:	66 90                	xchg   ax,ax
  102c99:	66 90                	xchg   ax,ax
  102c9b:	66 90                	xchg   ax,ax
  102c9d:	66 90                	xchg   ax,ax
  102c9f:	66 90                	xchg   ax,ax
  102ca1:	66 90                	xchg   ax,ax
  102ca3:	66 90                	xchg   ax,ax
  102ca5:	66 90                	xchg   ax,ax
  102ca7:	66 90                	xchg   ax,ax
  102ca9:	66 90                	xchg   ax,ax
  102cab:	66 90                	xchg   ax,ax
  102cad:	66 90                	xchg   ax,ax
  102caf:	66 90                	xchg   ax,ax
  102cb1:	66 90                	xchg   ax,ax
  102cb3:	66 90                	xchg   ax,ax
  102cb5:	66 90                	xchg   ax,ax
  102cb7:	66 90                	xchg   ax,ax
  102cb9:	66 90                	xchg   ax,ax
  102cbb:	66 90                	xchg   ax,ax
  102cbd:	66 90                	xchg   ax,ax
  102cbf:	66 90                	xchg   ax,ax
  102cc1:	66 90                	xchg   ax,ax
  102cc3:	66 90                	xchg   ax,ax
  102cc5:	66 90                	xchg   ax,ax
  102cc7:	66 90                	xchg   ax,ax
  102cc9:	66 90                	xchg   ax,ax
  102ccb:	66 90                	xchg   ax,ax
  102ccd:	66 90                	xchg   ax,ax
  102ccf:	66 90                	xchg   ax,ax
  102cd1:	66 90                	xchg   ax,ax
  102cd3:	66 90                	xchg   ax,ax
  102cd5:	66 90                	xchg   ax,ax
  102cd7:	66 90                	xchg   ax,ax
  102cd9:	66 90                	xchg   ax,ax
  102cdb:	66 90                	xchg   ax,ax
  102cdd:	66 90                	xchg   ax,ax
  102cdf:	66 90                	xchg   ax,ax
  102ce1:	66 90                	xchg   ax,ax
  102ce3:	66 90                	xchg   ax,ax
  102ce5:	66 90                	xchg   ax,ax
  102ce7:	66 90                	xchg   ax,ax
  102ce9:	66 90                	xchg   ax,ax
  102ceb:	66 90                	xchg   ax,ax
  102ced:	66 90                	xchg   ax,ax
  102cef:	66 90                	xchg   ax,ax
  102cf1:	66 90                	xchg   ax,ax
  102cf3:	66 90                	xchg   ax,ax
  102cf5:	66 90                	xchg   ax,ax
  102cf7:	66 90                	xchg   ax,ax
  102cf9:	66 90                	xchg   ax,ax
  102cfb:	66 90                	xchg   ax,ax
  102cfd:	66 90                	xchg   ax,ax
  102cff:	66 90                	xchg   ax,ax
  102d01:	66 90                	xchg   ax,ax
  102d03:	66 90                	xchg   ax,ax
  102d05:	66 90                	xchg   ax,ax
  102d07:	66 90                	xchg   ax,ax
  102d09:	66 90                	xchg   ax,ax
  102d0b:	66 90                	xchg   ax,ax
  102d0d:	66 90                	xchg   ax,ax
  102d0f:	66 90                	xchg   ax,ax
  102d11:	66 90                	xchg   ax,ax
  102d13:	66 90                	xchg   ax,ax
  102d15:	66 90                	xchg   ax,ax
  102d17:	66 90                	xchg   ax,ax
  102d19:	66 90                	xchg   ax,ax
  102d1b:	66 90                	xchg   ax,ax
  102d1d:	66 90                	xchg   ax,ax
  102d1f:	66 90                	xchg   ax,ax
  102d21:	66 90                	xchg   ax,ax
  102d23:	66 90                	xchg   ax,ax
  102d25:	66 90                	xchg   ax,ax
  102d27:	66 90                	xchg   ax,ax
  102d29:	66 90                	xchg   ax,ax
  102d2b:	66 90                	xchg   ax,ax
  102d2d:	66 90                	xchg   ax,ax
  102d2f:	66 90                	xchg   ax,ax
  102d31:	66 90                	xchg   ax,ax
  102d33:	66 90                	xchg   ax,ax
  102d35:	66 90                	xchg   ax,ax
  102d37:	66 90                	xchg   ax,ax
  102d39:	66 90                	xchg   ax,ax
  102d3b:	66 90                	xchg   ax,ax
  102d3d:	66 90                	xchg   ax,ax
  102d3f:	66 90                	xchg   ax,ax
  102d41:	66 90                	xchg   ax,ax
  102d43:	66 90                	xchg   ax,ax
  102d45:	66 90                	xchg   ax,ax
  102d47:	66 90                	xchg   ax,ax
  102d49:	66 90                	xchg   ax,ax
  102d4b:	66 90                	xchg   ax,ax
  102d4d:	66 90                	xchg   ax,ax
  102d4f:	66 90                	xchg   ax,ax
  102d51:	66 90                	xchg   ax,ax
  102d53:	66 90                	xchg   ax,ax
  102d55:	66 90                	xchg   ax,ax
  102d57:	66 90                	xchg   ax,ax
  102d59:	66 90                	xchg   ax,ax
  102d5b:	66 90                	xchg   ax,ax
  102d5d:	66 90                	xchg   ax,ax
  102d5f:	66 90                	xchg   ax,ax
  102d61:	66 90                	xchg   ax,ax
  102d63:	66 90                	xchg   ax,ax
  102d65:	66 90                	xchg   ax,ax
  102d67:	66 90                	xchg   ax,ax
  102d69:	66 90                	xchg   ax,ax
  102d6b:	66 90                	xchg   ax,ax
  102d6d:	66 90                	xchg   ax,ax
  102d6f:	66 90                	xchg   ax,ax
  102d71:	66 90                	xchg   ax,ax
  102d73:	66 90                	xchg   ax,ax
  102d75:	66 90                	xchg   ax,ax
  102d77:	66 90                	xchg   ax,ax
  102d79:	66 90                	xchg   ax,ax
  102d7b:	66 90                	xchg   ax,ax
  102d7d:	66 90                	xchg   ax,ax
  102d7f:	66 90                	xchg   ax,ax
  102d81:	66 90                	xchg   ax,ax
  102d83:	66 90                	xchg   ax,ax
  102d85:	66 90                	xchg   ax,ax
  102d87:	66 90                	xchg   ax,ax
  102d89:	66 90                	xchg   ax,ax
  102d8b:	66 90                	xchg   ax,ax
  102d8d:	66 90                	xchg   ax,ax
  102d8f:	66 90                	xchg   ax,ax
  102d91:	66 90                	xchg   ax,ax
  102d93:	66 90                	xchg   ax,ax
  102d95:	66 90                	xchg   ax,ax
  102d97:	66 90                	xchg   ax,ax
  102d99:	66 90                	xchg   ax,ax
  102d9b:	66 90                	xchg   ax,ax
  102d9d:	66 90                	xchg   ax,ax
  102d9f:	66 90                	xchg   ax,ax
  102da1:	66 90                	xchg   ax,ax
  102da3:	66 90                	xchg   ax,ax
  102da5:	66 90                	xchg   ax,ax
  102da7:	66 90                	xchg   ax,ax
  102da9:	66 90                	xchg   ax,ax
  102dab:	66 90                	xchg   ax,ax
  102dad:	66 90                	xchg   ax,ax
  102daf:	66 90                	xchg   ax,ax
  102db1:	66 90                	xchg   ax,ax
  102db3:	66 90                	xchg   ax,ax
  102db5:	66 90                	xchg   ax,ax
  102db7:	66 90                	xchg   ax,ax
  102db9:	66 90                	xchg   ax,ax
  102dbb:	66 90                	xchg   ax,ax
  102dbd:	66 90                	xchg   ax,ax
  102dbf:	66 90                	xchg   ax,ax
  102dc1:	66 90                	xchg   ax,ax
  102dc3:	66 90                	xchg   ax,ax
  102dc5:	66 90                	xchg   ax,ax
  102dc7:	66 90                	xchg   ax,ax
  102dc9:	66 90                	xchg   ax,ax
  102dcb:	66 90                	xchg   ax,ax
  102dcd:	66 90                	xchg   ax,ax
  102dcf:	66 90                	xchg   ax,ax
  102dd1:	66 90                	xchg   ax,ax
  102dd3:	66 90                	xchg   ax,ax
  102dd5:	66 90                	xchg   ax,ax
  102dd7:	66 90                	xchg   ax,ax
  102dd9:	66 90                	xchg   ax,ax
  102ddb:	66 90                	xchg   ax,ax
  102ddd:	66 90                	xchg   ax,ax
  102ddf:	66 90                	xchg   ax,ax
  102de1:	66 90                	xchg   ax,ax
  102de3:	66 90                	xchg   ax,ax
  102de5:	66 90                	xchg   ax,ax
  102de7:	66 90                	xchg   ax,ax
  102de9:	66 90                	xchg   ax,ax
  102deb:	66 90                	xchg   ax,ax
  102ded:	66 90                	xchg   ax,ax
  102def:	66 90                	xchg   ax,ax
  102df1:	66 90                	xchg   ax,ax
  102df3:	66 90                	xchg   ax,ax
  102df5:	66 90                	xchg   ax,ax
  102df7:	66 90                	xchg   ax,ax
  102df9:	66 90                	xchg   ax,ax
  102dfb:	66 90                	xchg   ax,ax
  102dfd:	66 90                	xchg   ax,ax
  102dff:	66 90                	xchg   ax,ax
  102e01:	66 90                	xchg   ax,ax
  102e03:	66 90                	xchg   ax,ax
  102e05:	66 90                	xchg   ax,ax
  102e07:	66 90                	xchg   ax,ax
  102e09:	66 90                	xchg   ax,ax
  102e0b:	66 90                	xchg   ax,ax
  102e0d:	66 90                	xchg   ax,ax
  102e0f:	66 90                	xchg   ax,ax
  102e11:	66 90                	xchg   ax,ax
  102e13:	66 90                	xchg   ax,ax
  102e15:	66 90                	xchg   ax,ax
  102e17:	66 90                	xchg   ax,ax
  102e19:	66 90                	xchg   ax,ax
  102e1b:	66 90                	xchg   ax,ax
  102e1d:	66 90                	xchg   ax,ax
  102e1f:	66 90                	xchg   ax,ax
  102e21:	66 90                	xchg   ax,ax
  102e23:	66 90                	xchg   ax,ax
  102e25:	66 90                	xchg   ax,ax
  102e27:	66 90                	xchg   ax,ax
  102e29:	66 90                	xchg   ax,ax
  102e2b:	66 90                	xchg   ax,ax
  102e2d:	66 90                	xchg   ax,ax
  102e2f:	66 90                	xchg   ax,ax
  102e31:	66 90                	xchg   ax,ax
  102e33:	66 90                	xchg   ax,ax
  102e35:	66 90                	xchg   ax,ax
  102e37:	66 90                	xchg   ax,ax
  102e39:	66 90                	xchg   ax,ax
  102e3b:	66 90                	xchg   ax,ax
  102e3d:	66 90                	xchg   ax,ax
  102e3f:	66 90                	xchg   ax,ax
  102e41:	66 90                	xchg   ax,ax
  102e43:	66 90                	xchg   ax,ax
  102e45:	66 90                	xchg   ax,ax
  102e47:	66 90                	xchg   ax,ax
  102e49:	66 90                	xchg   ax,ax
  102e4b:	66 90                	xchg   ax,ax
  102e4d:	66 90                	xchg   ax,ax
  102e4f:	66 90                	xchg   ax,ax
  102e51:	66 90                	xchg   ax,ax
  102e53:	66 90                	xchg   ax,ax
  102e55:	66 90                	xchg   ax,ax
  102e57:	66 90                	xchg   ax,ax
  102e59:	66 90                	xchg   ax,ax
  102e5b:	66 90                	xchg   ax,ax
  102e5d:	66 90                	xchg   ax,ax
  102e5f:	66 90                	xchg   ax,ax
  102e61:	66 90                	xchg   ax,ax
  102e63:	66 90                	xchg   ax,ax
  102e65:	66 90                	xchg   ax,ax
  102e67:	66 90                	xchg   ax,ax
  102e69:	66 90                	xchg   ax,ax
  102e6b:	66 90                	xchg   ax,ax
  102e6d:	66 90                	xchg   ax,ax
  102e6f:	66 90                	xchg   ax,ax
  102e71:	66 90                	xchg   ax,ax
  102e73:	66 90                	xchg   ax,ax
  102e75:	66 90                	xchg   ax,ax
  102e77:	66 90                	xchg   ax,ax
  102e79:	66 90                	xchg   ax,ax
  102e7b:	66 90                	xchg   ax,ax
  102e7d:	66 90                	xchg   ax,ax
  102e7f:	66 90                	xchg   ax,ax
  102e81:	66 90                	xchg   ax,ax
  102e83:	66 90                	xchg   ax,ax
  102e85:	66 90                	xchg   ax,ax
  102e87:	66 90                	xchg   ax,ax
  102e89:	66 90                	xchg   ax,ax
  102e8b:	66 90                	xchg   ax,ax
  102e8d:	66 90                	xchg   ax,ax
  102e8f:	66 90                	xchg   ax,ax
  102e91:	66 90                	xchg   ax,ax
  102e93:	66 90                	xchg   ax,ax
  102e95:	66 90                	xchg   ax,ax
  102e97:	66 90                	xchg   ax,ax
  102e99:	66 90                	xchg   ax,ax
  102e9b:	66 90                	xchg   ax,ax
  102e9d:	66 90                	xchg   ax,ax
  102e9f:	66 90                	xchg   ax,ax
  102ea1:	66 90                	xchg   ax,ax
  102ea3:	66 90                	xchg   ax,ax
  102ea5:	66 90                	xchg   ax,ax
  102ea7:	66 90                	xchg   ax,ax
  102ea9:	66 90                	xchg   ax,ax
  102eab:	66 90                	xchg   ax,ax
  102ead:	66 90                	xchg   ax,ax
  102eaf:	66 90                	xchg   ax,ax
  102eb1:	66 90                	xchg   ax,ax
  102eb3:	66 90                	xchg   ax,ax
  102eb5:	66 90                	xchg   ax,ax
  102eb7:	66 90                	xchg   ax,ax
  102eb9:	66 90                	xchg   ax,ax
  102ebb:	66 90                	xchg   ax,ax
  102ebd:	66 90                	xchg   ax,ax
  102ebf:	66 90                	xchg   ax,ax
  102ec1:	66 90                	xchg   ax,ax
  102ec3:	66 90                	xchg   ax,ax
  102ec5:	66 90                	xchg   ax,ax
  102ec7:	66 90                	xchg   ax,ax
  102ec9:	66 90                	xchg   ax,ax
  102ecb:	66 90                	xchg   ax,ax
  102ecd:	66 90                	xchg   ax,ax
  102ecf:	66 90                	xchg   ax,ax
  102ed1:	66 90                	xchg   ax,ax
  102ed3:	66 90                	xchg   ax,ax
  102ed5:	66 90                	xchg   ax,ax
  102ed7:	66 90                	xchg   ax,ax
  102ed9:	66 90                	xchg   ax,ax
  102edb:	66 90                	xchg   ax,ax
  102edd:	66 90                	xchg   ax,ax
  102edf:	66 90                	xchg   ax,ax
  102ee1:	66 90                	xchg   ax,ax
  102ee3:	66 90                	xchg   ax,ax
  102ee5:	66 90                	xchg   ax,ax
  102ee7:	66 90                	xchg   ax,ax
  102ee9:	66 90                	xchg   ax,ax
  102eeb:	66 90                	xchg   ax,ax
  102eed:	66 90                	xchg   ax,ax
  102eef:	66 90                	xchg   ax,ax
  102ef1:	66 90                	xchg   ax,ax
  102ef3:	66 90                	xchg   ax,ax
  102ef5:	66 90                	xchg   ax,ax
  102ef7:	66 90                	xchg   ax,ax
  102ef9:	66 90                	xchg   ax,ax
  102efb:	66 90                	xchg   ax,ax
  102efd:	66 90                	xchg   ax,ax
  102eff:	66 90                	xchg   ax,ax
  102f01:	66 90                	xchg   ax,ax
  102f03:	66 90                	xchg   ax,ax
  102f05:	66 90                	xchg   ax,ax
  102f07:	66 90                	xchg   ax,ax
  102f09:	66 90                	xchg   ax,ax
  102f0b:	66 90                	xchg   ax,ax
  102f0d:	66 90                	xchg   ax,ax
  102f0f:	66 90                	xchg   ax,ax
  102f11:	66 90                	xchg   ax,ax
  102f13:	66 90                	xchg   ax,ax
  102f15:	66 90                	xchg   ax,ax
  102f17:	66 90                	xchg   ax,ax
  102f19:	66 90                	xchg   ax,ax
  102f1b:	66 90                	xchg   ax,ax
  102f1d:	66 90                	xchg   ax,ax
  102f1f:	66 90                	xchg   ax,ax
  102f21:	66 90                	xchg   ax,ax
  102f23:	66 90                	xchg   ax,ax
  102f25:	66 90                	xchg   ax,ax
  102f27:	66 90                	xchg   ax,ax
  102f29:	66 90                	xchg   ax,ax
  102f2b:	66 90                	xchg   ax,ax
  102f2d:	66 90                	xchg   ax,ax
  102f2f:	66 90                	xchg   ax,ax
  102f31:	66 90                	xchg   ax,ax
  102f33:	66 90                	xchg   ax,ax
  102f35:	66 90                	xchg   ax,ax
  102f37:	66 90                	xchg   ax,ax
  102f39:	66 90                	xchg   ax,ax
  102f3b:	66 90                	xchg   ax,ax
  102f3d:	66 90                	xchg   ax,ax
  102f3f:	66 90                	xchg   ax,ax
  102f41:	66 90                	xchg   ax,ax
  102f43:	66 90                	xchg   ax,ax
  102f45:	66 90                	xchg   ax,ax
  102f47:	66 90                	xchg   ax,ax
  102f49:	66 90                	xchg   ax,ax
  102f4b:	66 90                	xchg   ax,ax
  102f4d:	66 90                	xchg   ax,ax
  102f4f:	66 90                	xchg   ax,ax
  102f51:	66 90                	xchg   ax,ax
  102f53:	66 90                	xchg   ax,ax
  102f55:	66 90                	xchg   ax,ax
  102f57:	66 90                	xchg   ax,ax
  102f59:	66 90                	xchg   ax,ax
  102f5b:	66 90                	xchg   ax,ax
  102f5d:	66 90                	xchg   ax,ax
  102f5f:	66 90                	xchg   ax,ax
  102f61:	66 90                	xchg   ax,ax
  102f63:	66 90                	xchg   ax,ax
  102f65:	66 90                	xchg   ax,ax
  102f67:	66 90                	xchg   ax,ax
  102f69:	66 90                	xchg   ax,ax
  102f6b:	66 90                	xchg   ax,ax
  102f6d:	66 90                	xchg   ax,ax
  102f6f:	66 90                	xchg   ax,ax
  102f71:	66 90                	xchg   ax,ax
  102f73:	66 90                	xchg   ax,ax
  102f75:	66 90                	xchg   ax,ax
  102f77:	66 90                	xchg   ax,ax
  102f79:	66 90                	xchg   ax,ax
  102f7b:	66 90                	xchg   ax,ax
  102f7d:	66 90                	xchg   ax,ax
  102f7f:	66 90                	xchg   ax,ax
  102f81:	66 90                	xchg   ax,ax
  102f83:	66 90                	xchg   ax,ax
  102f85:	66 90                	xchg   ax,ax
  102f87:	66 90                	xchg   ax,ax
  102f89:	66 90                	xchg   ax,ax
  102f8b:	66 90                	xchg   ax,ax
  102f8d:	66 90                	xchg   ax,ax
  102f8f:	66 90                	xchg   ax,ax
  102f91:	66 90                	xchg   ax,ax
  102f93:	66 90                	xchg   ax,ax
  102f95:	66 90                	xchg   ax,ax
  102f97:	66 90                	xchg   ax,ax
  102f99:	66 90                	xchg   ax,ax
  102f9b:	66 90                	xchg   ax,ax
  102f9d:	66 90                	xchg   ax,ax
  102f9f:	66 90                	xchg   ax,ax
  102fa1:	66 90                	xchg   ax,ax
  102fa3:	66 90                	xchg   ax,ax
  102fa5:	66 90                	xchg   ax,ax
  102fa7:	66 90                	xchg   ax,ax
  102fa9:	66 90                	xchg   ax,ax
  102fab:	66 90                	xchg   ax,ax
  102fad:	66 90                	xchg   ax,ax
  102faf:	66 90                	xchg   ax,ax
  102fb1:	66 90                	xchg   ax,ax
  102fb3:	66 90                	xchg   ax,ax
  102fb5:	66 90                	xchg   ax,ax
  102fb7:	66 90                	xchg   ax,ax
  102fb9:	66 90                	xchg   ax,ax
  102fbb:	66 90                	xchg   ax,ax
  102fbd:	66 90                	xchg   ax,ax
  102fbf:	66 90                	xchg   ax,ax
  102fc1:	66 90                	xchg   ax,ax
  102fc3:	66 90                	xchg   ax,ax
  102fc5:	66 90                	xchg   ax,ax
  102fc7:	66 90                	xchg   ax,ax
  102fc9:	66 90                	xchg   ax,ax
  102fcb:	66 90                	xchg   ax,ax
  102fcd:	66 90                	xchg   ax,ax
  102fcf:	66 90                	xchg   ax,ax
  102fd1:	66 90                	xchg   ax,ax
  102fd3:	66 90                	xchg   ax,ax
  102fd5:	66 90                	xchg   ax,ax
  102fd7:	66 90                	xchg   ax,ax
  102fd9:	66 90                	xchg   ax,ax
  102fdb:	66 90                	xchg   ax,ax
  102fdd:	66 90                	xchg   ax,ax
  102fdf:	66 90                	xchg   ax,ax
  102fe1:	66 90                	xchg   ax,ax
  102fe3:	66 90                	xchg   ax,ax
  102fe5:	66 90                	xchg   ax,ax
  102fe7:	66 90                	xchg   ax,ax
  102fe9:	66 90                	xchg   ax,ax
  102feb:	66 90                	xchg   ax,ax
  102fed:	66 90                	xchg   ax,ax
  102fef:	66 90                	xchg   ax,ax
  102ff1:	66 90                	xchg   ax,ax
  102ff3:	66 90                	xchg   ax,ax
  102ff5:	66 90                	xchg   ax,ax
  102ff7:	66 90                	xchg   ax,ax
  102ff9:	66 90                	xchg   ax,ax
  102ffb:	66 90                	xchg   ax,ax
  102ffd:	66 90                	xchg   ax,ax
  102fff:	90                   	nop

Disassembly of section .text.__x86.get_pc_thunk.ax:

00103000 <__x86.get_pc_thunk.ax>:
  103000:	8b 04 24             	mov    eax,DWORD PTR [esp]
  103003:	c3                   	ret    

Disassembly of section .text.__x86.get_pc_thunk.bx:

00103004 <__x86.get_pc_thunk.bx>:
  103004:	8b 1c 24             	mov    ebx,DWORD PTR [esp]
  103007:	c3                   	ret    
