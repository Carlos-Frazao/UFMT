import { Column, Entity, PrimaryGeneratedColumn } from 'typeorm';

@Entity()
export class Personagem {
  @PrimaryGeneratedColumn()
  id!: number;

  @Column()
  titulo!: string;

  @Column('text')
  conteudo!: string;

  @Column()
  imagem!: string;

  @Column()
  ordem!: number;

  @Column()
  afiliacao!: string;
}
